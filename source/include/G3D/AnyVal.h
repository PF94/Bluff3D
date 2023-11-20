/**
 @file AnyVal.h
 @author Morgan McGuire
 @created 2006-06-11
 @edited  2006-06-11
 */

#ifndef G3D_ANYVAL_H
#define G3D_ANYVAL_H

#include "platform.h"
#include <string>
#include "Array.h"
#include "TextInput.h"

namespace G3D {
// Forward declarations for G3D types
class Vector2;
class Vector3;
class Vector4;
class Color3;
class Color4;
class Quat;
class Matrix3;
class Matrix4;
class CoordinateFrame;
class TextInput;
class TextOutput;
class BinaryInput;
class BinaryOutput;

/**
 A generic value, useful for defining property trees that can
 be loaded from and saved to disk.  The values are intentionally
 restricted to a small set.

 See also boost::any for a more general puprose but slightly harder to use
 "any" for C++.

 The semantics of operator[] and the get() methods are slightly different;
 operator[] acts more like a scripting language that automatically extends
 arrays and tables instead of generating errors.  get() has more strict semantics,
 like a C++ class.

 Example:
 <pre>
    AnyVal dict(AnyVal::TABLE);

    dict["enabled"] = AnyVal(true);
    dict["weight"] = 100;
    dict["angular velocity"] = Vector3(1, -3, 4.5);

    TextOutput t("c:/tmp/test.txt");
    dict.serialize(t);
    t.commit();

    // Reading (using defaults to handle errors)
    // If there was no "enabled" value, this will return the default instead of failing
    bool enabled = dict.get("enabled").boolean(true);
  </pre>

  <p>
  <b>What's the difference from boost::any?</b>
  <br>I think that AnyVal will be easier for novice C++ users.  It addresses the problem that
   even though G3D::TextInput makes reading configuration files extremely simple, many people
   still don't use it.  So AnyVal makes it ridiculously simple to read and write a tree of G3D 
   types to a file. 

   <i>AnyVal:</i>
<pre>
{
AnyVal tree(TextInput("config.txt"));

bool enabled = tree.get("enabled", false);
Vector3 direction = tree.get("direction", Vector3::zero());
...
}
</pre>

<i>boost:</i>
<pre>
{
bool enabled = false;
Vector3 direction;
Table<boost::any> tree;

 ...write lots of file parsing code...

   if (tree.containsKey("enabled")) {
      const boost::any& val = tree["enabled"];
      try
      {
        enabled = any_cast<bool>(val);
      }
      catch(const boost::bad_any_cast &)
      {
      }
    }

   if (tree.containsKey("direction")) {
      const boost::any& val = tree["direction"];
      try
      {
        direction = any_cast<Vector3>(val);
      }
      catch(const boost::bad_any_cast &)
      {
      }
    }
   ...
}
</pre>
 */
class AnyVal {
public:

    /** 
      Arrays and tables have heterogeneous element types.
     */
    enum Type {
        NIL, 
        NUMBER,
        BOOLEAN, 
        STRING, 
        VECTOR2, 
        VECTOR3, 
        VECTOR4, 
        MATRIX3, 
        MATRIX4, 
        QUAT, 
        COORDINATEFRAME, 
        COLOR3, 
        COLOR4, 
        ARRAY, 
        TABLE};

    /** Base class for all AnyVal exceptions.*/
    class Exception {
    public:
        virtual ~Exception() {}
    };

    /** Thrown when an inappropriate operation is performed (e.g., operator[] on a number) */
    class WrongType : public Exception {
    public:
        Type        expected;
        Type        actual;
        WrongType() : expected(NIL), actual(NIL) {}
        WrongType(Type e, Type a) : expected(e), actual(a) {}
    };

    /** Thrown by operator[] when a key is not present. */
    class KeyNotFound : public Exception {
    public:
        std::string key;
        KeyNotFound() {}
        KeyNotFound(const std::string& k) : key(k) {}
    };

    class IndexOutOfBounds : public Exception {
    public:
        int     index;
        int     size;
        IndexOutOfBounds() : index(0), size(0) {}
        IndexOutOfBounds(int i, int s) : index(i), size(s) {}
    };

    /** Thrown when deserialize() when the input is incorrectly formatted. */
    class CorruptText : public Exception {
    public:
        std::string      message;

        /** Token where the problem occurred.*/
        G3D::Token       token;

        CorruptText() {}
        CorruptText(const std::string& s, const G3D::Token& t) : message(s), token(t) {}
    };

private:

    void*  m_value;
    Type   m_type;

public:

    AnyVal();

    /** Deserialize */
    explicit AnyVal(G3D::TextInput& t);

    ///** Deserialize */
    //explicit AnyVal(G3D::BinaryInput& t);

    /** Construct a number */
    AnyVal(double);

    // Explicit to avoid ambiguity with the 'double' constructor
    // when an integer type is constructed
    explicit AnyVal(bool);
    AnyVal(const G3D::Vector2&);
    AnyVal(const G3D::Vector3&);
    AnyVal(const G3D::Vector4&);

    AnyVal(const G3D::Color3&);
    AnyVal(const G3D::Color4&);

    AnyVal(const std::string&);
    AnyVal(const char*);

    AnyVal(const G3D::Quat&);

    AnyVal(const G3D::CoordinateFrame&);
    AnyVal(const G3D::Matrix3&);
    AnyVal(const G3D::Matrix4&);

    AnyVal(const AnyVal&);

    AnyVal(Type arrayOrTable);

    AnyVal& operator=(const AnyVal&);

    /** Frees the underlying storage */
    ~AnyVal();

    Type type() const;

    void serialize(G3D::TextOutput& t) const;
    //void serialize(G3D::BinaryOutput& t) const;
    void deserialize(G3D::TextInput& t);
    //void deserialize(G3D::BinaryInput& t);

    /** If this value is not a number throws a WrongType exception. */
    double number() const;

    /** If this value is not a number, returns defaultVal. */
    double number(double defaultVal) const;

    bool boolean() const;
    bool boolean(bool b) const;

    const std::string& string() const;
    const std::string& string(const std::string& defaultVal) const;

    const G3D::Vector2& vector2() const;
    const G3D::Vector2& vector2(const G3D::Vector2& defaultVal) const;

    const G3D::Vector3& vector3() const;
    const G3D::Vector3& vector3(const G3D::Vector3& defaultVal) const;

    const G3D::Vector4& vector4() const;
    const G3D::Vector4& vector4(const G3D::Vector4& defaultVal) const;

    const G3D::Color3& color3() const;
    const G3D::Color3& color3(const G3D::Color3& defaultVal) const;

    const G3D::Color4& color4() const;
    const G3D::Color4& color4(const G3D::Color4& defaultVal) const;

    const G3D::CoordinateFrame& coordinateFrame() const;
    const G3D::CoordinateFrame& coordinateFrame(const G3D::CoordinateFrame& defaultVal) const;

    const G3D::Matrix3& matrix3() const;
    const G3D::Matrix3& matrix3(const G3D::Matrix3& defaultVal) const;

    const G3D::Matrix4& matrix4() const;
    const G3D::Matrix4& matrix4(const G3D::Matrix4& defaultVal) const;

    const G3D::Quat& quat() const;
    const G3D::Quat& quat(const G3D::Quat& defaultVal) const;

    /** Array dereference.  If the index is out of bounds, IndexOutOfBounds is thrown */
    const AnyVal& operator[](int) const;

    /** Extend this array by one element. */
    void append(const AnyVal&);

    /** If the index is out of bounds, the array is resized.  If the index is negative,
        IndexOutOfBounds is thrown.*/
    AnyVal& operator[](int);

    /** If @a i is out of bounds or this is not an ARRAY, defaultVal is returned.*/
    const AnyVal& get(int i, const AnyVal& defaultVal) const;

    /** If out of bounds, IndexOutOfBounds is thrown. */
    const AnyVal& get(int i) const;

    /** Returns defaultVal if this is not a TABLE or the key is not found. */
    const AnyVal& get(const std::string& key, const AnyVal& defaultVal) const;

    /** Throws KeyNotFound exception if the key is not present.*/
    const AnyVal& get(const std::string& key) const;

    /** Table reference */
    const AnyVal& operator[](const std::string&) const;

    /** Table reference.  If the element does not exist, it is created. */
    AnyVal& operator[](const std::string&);

    /** Number of elements for an array or table.*/
    int size() const;

    /** For a table, returns the keys. */
    void getKeys(G3D::Array<std::string>&) const;
};

}

#endif
