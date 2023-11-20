/** 
 @file AnyVal.cpp
 @author Morgan McGuire
 @created 2006-06-11
 @edited  2006-06-11
 */

#include "G3D/AnyVal.h"
#include "G3D/Array.h"
#include "G3D/stringutils.h"
#include "G3D/Table.h"
#include "G3D/Vector2.h"
#include "G3D/Vector3.h"
#include "G3D/Vector4.h"
#include "G3D/Color3.h"
#include "G3D/Color4.h"
#include "G3D/Matrix3.h"
#include "G3D/Matrix4.h"
#include "G3D/CoordinateFrame.h"
#include "G3D/Quat.h"
#include "G3D/TextInput.h"
#include "G3D/TextOutput.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"

namespace G3D {

    AnyVal::AnyVal() : m_type(NIL), m_value(NULL) {
    }


    AnyVal::AnyVal(bool b) : m_type(BOOLEAN), m_value(new bool(b)) {
    }


    AnyVal::AnyVal(G3D::TextInput &t) {
        deserialize(t);
    }


/*AnyVal::AnyVal(G3D::BinaryInput& b) {
    deserialize(b);
}
*/

    AnyVal::AnyVal(double v) : m_type(NUMBER) {
        m_value = new double(v);
    }


    AnyVal::AnyVal(const Vector2 &v) : m_type(VECTOR2) {
        m_value = new Vector2(v);
    }


    AnyVal::AnyVal(const Vector3 &v) : m_type(VECTOR3) {
        m_value = new Vector3(v);
    }


    AnyVal::AnyVal(const Vector4 &v) : m_type(VECTOR4) {
        m_value = new Vector4(v);
    }


    AnyVal::AnyVal(const Color3 &v) : m_type(COLOR3) {
        m_value = new Color3(v);
    }


    AnyVal::AnyVal(const Color4 &v) : m_type(COLOR4) {
        m_value = new Color4(v);
    }


    AnyVal::AnyVal(const std::string &v) : m_type(STRING) {
        m_value = new std::string(v);
    }


    AnyVal::AnyVal(const char *v) : m_type(STRING) {
        m_value = new std::string(v);
    }


    AnyVal::AnyVal(const Quat &v) : m_type(QUAT) {
        m_value = new Quat(v);
    }


    AnyVal::AnyVal(const CoordinateFrame &v) : m_type(COORDINATEFRAME) {
        m_value = new CoordinateFrame(v);
    }


    AnyVal::AnyVal(const Matrix3 &v) : m_type(MATRIX3) {
        m_value = new Matrix3(v);
    }


    AnyVal::AnyVal(const Matrix4 &v) : m_type(MATRIX4) {
        m_value = new Matrix4(v);
    }


    AnyVal::AnyVal(const AnyVal &c) : m_type(NIL), m_value(NULL) {
        *this = c;
    }


    AnyVal::AnyVal(Type arrayOrTable) : m_type(NIL), m_value(NULL) {
        switch (arrayOrTable) {
            case ARRAY:
                m_type = ARRAY;
                m_value = new Array<AnyVal>();
                break;

            case TABLE:
                m_type = TABLE;
                m_value = new Table<std::string, AnyVal>();
                break;

            default:
                // Illegal!
                ;
        }
    }


    AnyVal::~AnyVal() {
        delete m_value;
        m_type = NIL;
        m_value = NULL;
    }


    AnyVal &AnyVal::operator=(const AnyVal &v) {
        delete m_value;
        m_value = NULL;
        m_type = v.m_type;

        switch (m_type) {
            case NIL:
                // Nothing to do
                break;

            case NUMBER:
                m_value = new double(*(double *) v.m_value);
                break;

            case BOOLEAN:
                m_value = new bool(*(bool *) v.m_value);
                break;

            case STRING:
                m_value = new std::string(*(std::string *) v.m_value);
                break;

            case VECTOR2:
                m_value = new Vector2(*(Vector2 *) v.m_value);
                break;

            case VECTOR3:
                m_value = new Vector3(*(Vector3 *) v.m_value);
                break;

            case VECTOR4:
                m_value = new Vector4(*(Vector4 *) v.m_value);
                break;

            case MATRIX3:
                m_value = new Matrix3(*(Matrix3 *) v.m_value);
                break;

            case MATRIX4:
                m_value = new Matrix4(*(Matrix4 *) v.m_value);
                break;

            case QUAT:
                m_value = new Quat(*(Quat *) v.m_value);
                break;

            case COORDINATEFRAME:
                m_value = new CoordinateFrame(*(CoordinateFrame *) v.m_value);
                break;

            case COLOR3:
                m_value = new Color3(*(Color3 *) v.m_value);
                break;

            case COLOR4:
                m_value = new Color4(*(Color4 *) v.m_value);
                break;

            case ARRAY:
                m_value = new Array<AnyVal>(*(Array<AnyVal> *) v.m_value);
                break;

            case TABLE:
                m_value = new Table<std::string, AnyVal>(*(Table<std::string, AnyVal> *) v.m_value);
                break;

            default:
                debugAssertM(false, "Internal error: no assignment operator for this type.");
        }

        return *this;
    }


    AnyVal::Type AnyVal::type() const {
        return m_type;
    }


    static bool legalIdentifier(const std::string &s) {
        if (s.size() == 0) {
            return false;
        }

        if (!isLetter(s[0]) || (s[0] == '_')) {
            return false;
        }

        bool ok = true;

        for (unsigned int i = 1; i < s.size(); ++i) {
                ok &= isDigit(s[i]) || isLetter(s[i]) || (s[i] == '_');
            }

        return ok;
    }


    void AnyVal::serialize(G3D::TextOutput &t) const {
        switch (m_type) {
            case NIL:
                t.writeSymbol("Nil");
                break;

            case NUMBER:
                t.printf("%g", *(double *) m_value);
                break;

            case BOOLEAN:
                if (*(bool *) m_value) {
                    t.printf("true");
                } else {
                    t.printf("false");
                }
                break;

            case STRING:
                t.writeString(*(std::string *) m_value);
                break;

            case VECTOR2:
                t.printf("V2(%g, %g)", ((Vector2 *) m_value)->x, ((Vector2 *) m_value)->y);
                break;

            case VECTOR3:
                t.printf("V3(%g, %g, %g)", ((Vector3 *) m_value)->x, ((Vector3 *) m_value)->y,
                         ((Vector3 *) m_value)->z);
                break;

            case VECTOR4:
                t.printf("V4(%g, %g, %g, %g)", ((Vector4 *) m_value)->x, ((Vector4 *) m_value)->y,
                         ((Vector4 *) m_value)->z, ((Vector4 *) m_value)->w);
                break;

            case MATRIX3: {
                const Matrix3 &m = *(Matrix3 *) m_value;
                t.printf("M3(\n");
                t.pushIndent();
                t.printf("%10.5f, %10.5f, %10.5f,\n%10.5f, %10.5f, %10.5f,\n%10.5f, %10.5f, %10.5f)",
                         m[0, 0], m[0, 1], m[0, 2],
                         m[1, 0], m[1, 1], m[1, 2],
                         m[2, 0], m[2, 1], m[2, 2]);
                t.popIndent();
            }
                break;

            case MATRIX4: {
                const Matrix4 &m = *(Matrix4 *) m_value;
                t.printf("M4(\n");
                t.pushIndent();
                t.printf(
                        "%10.5f, %10.5f, %10.5f, %10.5f,\n"
                        "%10.5f, %10.5f, %10.5f, %10.5f,\n"
                        "%10.5f, %10.5f, %10.5f, %10.5f,\n"
                        "%10.5f, %10.5f, %10.5f, %10.5f)",
                        m[0, 0], m[0, 1], m[0, 2], m[0, 3],
                        m[1, 0], m[1, 1], m[1, 2], m[1, 3],
                        m[2, 0], m[2, 1], m[2, 2], m[2, 3],
                        m[3, 0], m[3, 1], m[3, 2], m[3, 3]);
                t.popIndent();
            }
                break;

            case QUAT:
                t.printf("Q(%g, %g, %g, %g)", ((Quat *) m_value)->x, ((Quat *) m_value)->y, ((Quat *) m_value)->z,
                         ((Quat *) m_value)->w);
                break;

            case COORDINATEFRAME: {
                const CoordinateFrame &c = *(CoordinateFrame *) m_value;
                t.printf("CF(\n");
                t.pushIndent();
                t.printf(
                        "%10.5f, %10.5f, %10.5f,   %10.5f,\n"
                        "%10.5f, %10.5f, %10.5f,   %10.5f,\n"
                        "%10.5f, %10.5f, %10.5f,   %10.5f)",
                        c.rotation[0, 0], c.rotation[0, 1], c.rotation[0, 2], c.translation.x,
                        c.rotation[1, 0], c.rotation[1, 1], c.rotation[1, 2], c.translation.y,
                        c.rotation[2, 0], c.rotation[2, 1], c.rotation[2, 2], c.translation.z);
                t.popIndent();
            }
                break;

            case COLOR3:
                t.printf("C3(%g, %g, %g)", ((Color3 *) m_value)->r, ((Color3 *) m_value)->g, ((Color3 *) m_value)->b);
                break;

            case COLOR4:
                t.printf("C4(%g, %g, %g, %g)", ((Color4 *) m_value)->r, ((Color4 *) m_value)->g,
                         ((Color4 *) m_value)->b, ((Color4 *) m_value)->a);
                break;

            case ARRAY: {
                const Array<AnyVal> &a = *(Array<AnyVal> *) m_value;
                t.printf("[\n");
                t.pushIndent();
                for (int i = 0; i < a.size(); ++i) {
                        a[i].serialize(t);
                        if (i != a.size() - 1) {
                            t.printf(",\n");
                        }
                    }
                t.printf("]");
                t.popIndent();
            }
                break;

            case TABLE: {
                const Table<std::string, AnyVal> &a = *(Table<std::string, AnyVal> *) m_value;
                t.printf("{\n");
                t.pushIndent();
                Table<std::string, AnyVal>::Iterator i = a.begin();
                const Table<std::string, AnyVal>::Iterator end = a.end();
                while (i != end) {
                    // Quote names that are not legal C++ identifiers
                    if (!legalIdentifier(i->key)) {
                        t.printf("'%s' ", i->key.c_str());
                    } else {
                        t.writeSymbol(i->key);
                    }
                    t.printf("= ");

                    i->value.serialize(t);

                    if (i != end) {
                        t.printf(";\n\n");
                    }
                    ++i;
                }
                t.popIndent();
                t.printf("}");
            }
                break;

            default:
                debugAssertM(false, "Internal error: no serialize method for this type.");
        }
    }

/*
void AnyVal::serialize(G3D::BinaryOutput& t) const {
    alwaysAssertM(false, "TODO");
}
*/

    void AnyVal::deserialize(G3D::TextInput &t) {
        m_type = NIL;
        m_value = NULL;

        if (!t.hasMore()) {
            return;
        }

        switch (t.peek().type()) {
            case Token::NUMBER:
                m_type = NUMBER;
                m_value = new double(t.readNumber());
                break;

            case Token::STRING:
                m_type = STRING;
                m_value = new std::string(t.readString());
                break;

            case Token::SYMBOL: {
                std::string s = t.readSymbol();
                if (s == "NIL") {
                    break;

                } else if (s == "true") {

                    m_type = BOOLEAN;
                    m_value = new bool(true);

                } else if (s == "false") {

                    m_type = BOOLEAN;
                    m_value = new bool(false);

                } else if (s == "V2") {

                    t.readSymbol("(");
                    Vector2 v;
                    v.x = t.readNumber();
                    t.readSymbol(",");
                    v.y = t.readNumber();
                    t.readSymbol(")");
                    m_value = new Vector2(v);
                    m_type = VECTOR2;

                } else if (s == "V3") {

                    t.readSymbol("(");
                    Vector3 v;
                    v.x = t.readNumber();
                    t.readSymbol(",");
                    v.y = t.readNumber();
                    t.readSymbol(",");
                    v.z = t.readNumber();
                    t.readSymbol(")");
                    m_value = new Vector3(v);
                    m_type = VECTOR3;

                } else if (s == "V4") {

                    t.readSymbol("(");
                    Vector4 v;
                    v.x = t.readNumber();
                    t.readSymbol(",");
                    v.y = t.readNumber();
                    t.readSymbol(",");
                    v.z = t.readNumber();
                    t.readSymbol(",");
                    v.w = t.readNumber();
                    t.readSymbol(")");
                    m_value = new Vector4(v);
                    m_type = VECTOR4;

                } else if (s == "M3") {

                    t.readSymbol("(");
                    Matrix3 m;
                    for (int r = 0; r < 3; ++r) {
                            for (int c = 0; c < 3; ++c) {
                                    m[r][c] = (float) t.readNumber();
                                    if ((c != 2) || (r != 2)) {
                                        t.readSymbol(",");
                                    }
                                }
                        }
                    t.readSymbol(")");
                    m_value = new Matrix3(m);
                    m_type = MATRIX3;

                } else if (s == "M4") {

                    t.readSymbol("(");
                    Matrix4 m;
                    for (int r = 0; r < 4; ++r) {
                            for (int c = 0; c < 4; ++c) {
                                    m[r][c] = (float) t.readNumber();
                                    if ((c != 3) || (r != 3)) {
                                        t.readSymbol(",");
                                    }
                                }
                        }
                    t.readSymbol(")");
                    m_value = new Matrix4(m);
                    m_type = MATRIX4;

                } else if (s == "Q") {

                    t.readSymbol("(");
                    Quat q;
                    q.x = t.readNumber();
                    t.readSymbol(",");
                    q.y = t.readNumber();
                    t.readSymbol(",");
                    q.z = t.readNumber();
                    t.readSymbol(",");
                    q.w = t.readNumber();
                    t.readSymbol(")");
                    m_value = new Quat(q);
                    m_type = QUAT;

                } else if (s == "CF") {

                    t.readSymbol("(");
                    CoordinateFrame m;
                    for (int r = 0; r < 3; ++r) {
                            for (int c = 0; c < 3; ++c) {
                                    m.rotation[r][c] = t.readNumber();
                                }
                            m.translation[r] = t.readNumber();
                            if (r != 2) {
                                t.readSymbol(",");
                            }
                        }
                    t.readSymbol(")");
                    m_value = new CoordinateFrame(m);
                    m_type = COORDINATEFRAME;

                } else if (s == "C3") {

                    t.readSymbol("(");
                    Color3 c;
                    c.r = t.readNumber();
                    t.readSymbol(",");
                    c.g = t.readNumber();
                    t.readSymbol(",");
                    c.b = t.readNumber();
                    t.readSymbol(")");
                    m_value = new Color3(c);
                    m_type = COLOR3;

                } else if (s == "C4") {

                    t.readSymbol("(");
                    Color4 c;
                    c.r = t.readNumber();
                    t.readSymbol(",");
                    c.g = t.readNumber();
                    t.readSymbol(",");
                    c.b = t.readNumber();
                    t.readSymbol(",");
                    c.a = t.readNumber();
                    t.readSymbol(")");
                    m_value = new Color4(c);
                    m_type = COLOR4;

                } else if (s == "[") {

                    // Array
                    m_type = ARRAY;
                    m_value = new Array<AnyVal>();
                    Array<AnyVal> &a = *(Array<AnyVal> *) m_value;

                    Token peek = t.peek();
                    while ((peek.type() != Token::SYMBOL) || (peek.string() != "]")) {
                        // Avoid copying large objects
                        a.next().deserialize(t);

                        peek = t.peek();
                        if (peek.type() != Token::SYMBOL) {
                            throw CorruptText("Expected ',' or ']'", peek);
                        } else if (peek.string() == ",") {
                            t.readSymbol(",");
                        } else if (peek.string() != "]") {
                            throw CorruptText("Missing ']'", peek);
                        }
                    }
                    t.readSymbol("]");

                } else if (s == "{") {

                    // Table
                    m_type = TABLE;
                    m_value = new Table<std::string, AnyVal>();
                    Table<std::string, AnyVal> &a = *(Table<std::string, AnyVal> *) m_value;

                    Token peek = t.peek();
                    while ((peek.type() != Token::SYMBOL) || (peek.string() != "}")) {

                        std::string key;
                        // Get the name
                        if (peek.type() == Token::SYMBOL) {
                            key = t.readSymbol();
                        } else if (peek.extendedType() == Token::SINGLE_QUOTED_TYPE) {
                            key = t.readString();
                        } else {
                            // Parse error: TODO
                        }

                        t.readSymbol("=");

                        // Avoid copying large values
                        a.set(key, AnyVal());
                        a[key].deserialize(t);

                        peek = t.peek();
                        if (peek.type() != Token::SYMBOL) {
                            throw CorruptText("Missing expected ';' or '}'", peek);
                        } else if (peek.string() == ";") {
                            t.readSymbol(";");
                        } else if (peek.string() != "}") {
                            throw CorruptText("Missing '}'", peek);
                        }
                    }
                    t.readSymbol("}");

                } else {
                    throw CorruptText("Invalid value type.", t.peek());
                } // dispatch on symbol type
            } // scope
                break;
        }
    }

/*
void AnyVal::deserialize(G3D::BinaryInput& t) {
    alwaysAssertM(false, "TODO");
}
*/

    AnyVal &AnyVal::operator[](const std::string &key) {
        if (m_type != TABLE) {
            throw WrongType(TABLE, m_type);
        }

        Table<std::string, AnyVal> &t = *(Table<std::string, AnyVal> *) m_value;

        if (!t.containsKey(key)) {
            t.set(key, AnyVal());
        }

        return t[key];
    }


    const AnyVal &AnyVal::operator[](const std::string &key) const {
        if (m_type != TABLE) {
            throw WrongType(TABLE, m_type);
        }

        const Table<std::string, AnyVal> &t = *(const Table<std::string, AnyVal> *) m_value;

        if (!t.containsKey(key)) {
            throw KeyNotFound(key);
        }

        return t[key];
    }


    void AnyVal::append(const AnyVal &v) {
        if (m_type != ARRAY) {
            throw WrongType(ARRAY, m_type);
        }

        Array<AnyVal> &a = *(Array<AnyVal> *) m_value;
        a.append(v);
    }


    void AnyVal::getKeys(Array<std::string> &keys) const {
        if (m_type != TABLE) {
            throw WrongType(TABLE, m_type);
        }

        const Table<std::string, AnyVal> &t = *(const Table<std::string, AnyVal> *) m_value;
        t.getKeys(keys);
    }


    int AnyVal::size() const {
        switch (m_type) {
            case TABLE: {
                const Table<std::string, AnyVal> &t = *(const Table<std::string, AnyVal> *) m_value;
                return t.size();
            }

            case ARRAY: {
                const Array<AnyVal> &a = *(Array<AnyVal> *) m_value;
                return a.size();
            }

            default:
                throw WrongType(ARRAY, m_type);
        }
    }


    AnyVal &AnyVal::operator[](int i) {
        if (m_type != ARRAY) {
            throw WrongType(ARRAY, m_type);
        }

        Array<AnyVal> &a = *(Array<AnyVal> *) m_value;

        if (i < 0) {
            throw IndexOutOfBounds(i, a.size());
        }

        if (a.size() <= i) {
            a.resize(i + 1);
        }

        return a[i];
    }


    const AnyVal &AnyVal::operator[](int i) const {
        if (m_type != ARRAY) {
            throw WrongType(ARRAY, m_type);
        }

        const Array<AnyVal> &a = *(Array<AnyVal> *) m_value;

        if (a.size() <= i || i < 0) {
            throw IndexOutOfBounds(i, a.size());
        }

        return a[i];
    }


    bool AnyVal::boolean() const {
        if (m_type != BOOLEAN) {
            throw WrongType(BOOLEAN, m_type);
        }

        return *(bool *) m_value;
    }


    bool AnyVal::boolean(bool defaultVal) const {
        if (m_type != BOOLEAN) {
            throw WrongType(BOOLEAN, m_type);
        }

        return *(bool *) m_value;
    }


    const std::string &AnyVal::string() const {
        if (m_type != STRING) {
            throw WrongType(STRING, m_type);
        }

        return *(std::string *) m_value;
    }


    const std::string &AnyVal::string(const std::string &defaultVal) const {
        if (m_type != STRING) {
            return defaultVal;
        } else {
            return *(std::string *) m_value;
        }
    }


    double AnyVal::number() const {
        if (m_type != NUMBER) {
            throw WrongType(NUMBER, m_type);
        }

        return *(double *) m_value;
    }


    double AnyVal::number(double defaultVal) const {
        if (m_type != NUMBER) {
            return defaultVal;
        } else {
            return *(double *) m_value;
        }
    }


    const Vector2 &AnyVal::vector2() const {
        if (m_type != VECTOR2) {
            throw WrongType(VECTOR2, m_type);
        }

        return *(Vector2 *) m_value;
    }


    const Vector2 &AnyVal::vector2(const Vector2 &defaultVal) const {
        if (m_type != VECTOR2) {
            return defaultVal;
        } else {
            return *(Vector2 *) m_value;
        }
    }


    const Vector3 &AnyVal::vector3() const {
        if (m_type != VECTOR3) {
            throw WrongType(VECTOR3, m_type);
        }

        return *(Vector3 *) m_value;
    }


    const Vector3 &AnyVal::vector3(const Vector3 &defaultVal) const {
        if (m_type != VECTOR3) {
            return defaultVal;
        } else {
            return *(Vector3 *) m_value;
        }
    }


    const Vector4 &AnyVal::vector4() const {
        if (m_type != VECTOR4) {
            throw WrongType(VECTOR4, m_type);
        }

        return *(Vector4 *) m_value;
    }


    const Vector4 &AnyVal::vector4(const Vector4 &defaultVal) const {
        if (m_type != VECTOR4) {
            return defaultVal;
        } else {
            return *(Vector4 *) m_value;
        }
    }


    const CoordinateFrame &AnyVal::coordinateFrame() const {
        if (m_type != COORDINATEFRAME) {
            throw WrongType(COORDINATEFRAME, m_type);
        }

        return *(CoordinateFrame *) m_value;
    }


    const CoordinateFrame &AnyVal::coordinateFrame(const CoordinateFrame &defaultVal) const {
        if (m_type != COORDINATEFRAME) {
            return defaultVal;
        } else {
            return *(CoordinateFrame *) m_value;
        }
    }


    const Matrix3 &AnyVal::matrix3(const Matrix3 &defaultVal) const {
        if (m_type != MATRIX3) {
            return defaultVal;
        } else {
            return *(Matrix3 *) m_value;
        }
    }


    const Matrix3 &AnyVal::matrix3() const {
        if (m_type != MATRIX3) {
            throw WrongType(MATRIX3, m_type);
        }

        return *(Matrix3 *) m_value;
    }


    const Matrix4 &AnyVal::matrix4(const Matrix4 &defaultVal) const {
        if (m_type != MATRIX4) {
            return defaultVal;
        } else {
            return *(Matrix4 *) m_value;
        }
    }


    const Matrix4 &AnyVal::matrix4() const {
        if (m_type != MATRIX4) {
            throw WrongType(MATRIX4, m_type);
        }

        return *(Matrix4 *) m_value;
    }


    const Quat &AnyVal::quat(const Quat &defaultVal) const {
        if (m_type != QUAT) {
            return defaultVal;
        } else {
            return *(Quat *) m_value;
        }
    }


    const Quat &AnyVal::quat() const {
        if (m_type != QUAT) {
            throw WrongType(QUAT, m_type);
        }

        return *(Quat *) m_value;
    }


    const AnyVal &AnyVal::get(const std::string &key, const AnyVal &defaultVal) const {
        if (m_type != TABLE) {
            return defaultVal;
        }

        const Table<std::string, AnyVal> &t = *(const Table<std::string, AnyVal> *) m_value;

        if (t.containsKey(key)) {
            return t[key];
        } else {
            return defaultVal;
        }
    }


    const AnyVal &AnyVal::get(const std::string &key) const {
        if (m_type != TABLE) {
            throw WrongType(TABLE, m_type);
        }

        const Table<std::string, AnyVal> &t = *(const Table<std::string, AnyVal> *) m_value;

        if (t.containsKey(key)) {
            return t[key];
        } else {
            throw KeyNotFound(key);
        }
    }


    const AnyVal &AnyVal::get(int i, const AnyVal &defaultVal) const {
        if (m_type != ARRAY) {
            return defaultVal;
        }

        const Array<AnyVal> &a = *(const Array<AnyVal> *) m_value;

        if ((i >= 0) && (i < a.size())) {
            return a[i];
        } else {
            return defaultVal;
        }
    }


    const AnyVal &AnyVal::get(int i) const {
        if (m_type != ARRAY) {
            throw WrongType(ARRAY, m_type);
        }

        const Array<AnyVal> &a = *(const Array<AnyVal> *) m_value;

        if ((i >= 0) && (i < a.size())) {
            return a[i];
        } else {
            throw IndexOutOfBounds(i, a.size());
        }
    }

}
