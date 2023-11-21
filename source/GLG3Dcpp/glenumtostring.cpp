/**
  @file glenumtostring.cpp

  @maintainer Morgan McGuire, matrix@graphics3d.com
  @cite       Written by Seth Block
  @created 2001-08-05
  @edited  2004-05-31
*/

#include "GLG3D/getOpenGLState.h"

namespace G3D {

    const char *GLenumToString(GLenum i) {

        switch (i) {

            // Use a macro to take a little bit out of the repetitive
            // nature of the following code.
#define S(gl) case gl: return #gl

            S(GL_LIGHTING);

            S(GL_ACCUM);
            S(GL_LOAD);
            S(GL_RETURN);
            S(GL_MULT);
            S(GL_ADD);

            S(GL_NEVER);
            S(GL_LESS);
            S(GL_EQUAL);
            S(GL_LEQUAL);
            S(GL_GREATER);
            S(GL_NOTEQUAL);
            S(GL_GEQUAL);
            S(GL_ALWAYS);

                //S(GL_CURRENT_BIT);
            S(GL_POINT_BIT);
                //S(GL_LINE_BIT);
            S(GL_POLYGON_BIT);
            S(GL_POLYGON_STIPPLE_BIT);
            S(GL_PIXEL_MODE_BIT);
            S(GL_LIGHTING_BIT);
            S(GL_FOG_BIT);
                //S(GL_DEPTH_BUFFER_BIT);
                //S(GL_ACCUM_BUFFER_BIT);
            S(GL_STENCIL_BUFFER_BIT);
            S(GL_VIEWPORT_BIT);
            S(GL_TRANSFORM_BIT);
            S(GL_ENABLE_BIT);
                //S(GL_COLOR_BUFFER_BIT);
            S(GL_HINT_BIT);
            S(GL_EVAL_BIT);
                //S(GL_POINTS);
                //S(GL_LINES);
                //S(GL_LINE_LOOP);
            S(GL_LINE_STRIP);
            S(GL_TRIANGLES);
            S(GL_TRIANGLE_STRIP);
            S(GL_TRIANGLE_FAN);
            S(GL_QUADS);
                //S(GL_QUAD_STRIP);
            S(GL_POLYGON);

            S(GL_ZERO);
            S(GL_ONE);
            S(GL_SRC_COLOR);
            S(GL_ONE_MINUS_SRC_COLOR);
            S(GL_SRC_ALPHA);
            S(GL_ONE_MINUS_SRC_ALPHA);

                //S(GL_TRUE);
                //S(GL_FALSE);
            S(GL_CLIP_PLANE0);
            S(GL_CLIP_PLANE1);
            S(GL_CLIP_PLANE2);
            S(GL_CLIP_PLANE3);
            S(GL_CLIP_PLANE4);
            S(GL_CLIP_PLANE5);
            S(GL_BYTE);
            S(GL_UNSIGNED_BYTE);
            S(GL_SHORT);
            S(GL_UNSIGNED_SHORT);
            S(GL_INT);
            S(GL_UNSIGNED_INT);
            S(GL_FLOAT);
            S(GL_2_BYTES);
            S(GL_3_BYTES);
            S(GL_4_BYTES);
            S(GL_DOUBLE);
                //S(GL_NONE);
                //S(GL_FRONT_LEFT);
            S(GL_FRONT_RIGHT);
            S(GL_BACK_LEFT);
            S(GL_BACK_RIGHT);
            S(GL_FRONT);
            S(GL_BACK);
            S(GL_LEFT);
            S(GL_RIGHT);
            S(GL_FRONT_AND_BACK);

                //S(GL_NO_ERROR);
            S(GL_INVALID_ENUM);
            S(GL_INVALID_VALUE);
            S(GL_INVALID_OPERATION);
            S(GL_STACK_OVERFLOW);
            S(GL_STACK_UNDERFLOW);
            S(GL_OUT_OF_MEMORY);

            S(GL_2D);
            S(GL_3D);
            S(GL_3D_COLOR);
            S(GL_3D_COLOR_TEXTURE);
            S(GL_4D_COLOR_TEXTURE);

                //S(GL_EXP);
            S(GL_EXP2);

            S(GL_CW);
            S(GL_CCW);
            S(GL_CURRENT_COLOR);
            S(GL_CURRENT_INDEX);
            S(GL_CURRENT_NORMAL);
            S(GL_CURRENT_TEXTURE_COORDS);
            S(GL_CURRENT_RASTER_COLOR);
            S(GL_CURRENT_RASTER_INDEX);
            S(GL_CURRENT_RASTER_TEXTURE_COORDS);
            S(GL_CURRENT_RASTER_POSITION);
            S(GL_CURRENT_RASTER_POSITION_VALID);
            S(GL_CURRENT_RASTER_DISTANCE);
            S(GL_POINT_SMOOTH);
            S(GL_POINT_SIZE);
            S(GL_POINT_SIZE_RANGE);
            S(GL_POINT_SIZE_GRANULARITY);
            S(GL_LINE_SMOOTH);
            S(GL_LINE_WIDTH);

            S(GL_RED_BIAS);
            S(GL_ZOOM_X);
            S(GL_ZOOM_Y);
            S(GL_GREEN_SCALE);
            S(GL_GREEN_BIAS);
            S(GL_BLUE_SCALE);
            S(GL_BLUE_BIAS);
            S(GL_ALPHA_SCALE);
            S(GL_ALPHA_BIAS);
            S(GL_DEPTH_SCALE);
            S(GL_DEPTH_BIAS);
            S(GL_MAX_EVAL_ORDER);
            S(GL_MAX_LIGHTS);
            S(GL_MAX_CLIP_PLANES);
            S(GL_MAX_TEXTURE_SIZE);
            S(GL_MAX_PIXEL_MAP_TABLE);

                //S(GL_TEXTURE_WIDTH);
            S(GL_TEXTURE_HEIGHT);
            S(GL_TEXTURE_INTERNAL_FORMAT);
            S(GL_TEXTURE_BORDER_COLOR);
            S(GL_TEXTURE_BORDER);

            S(GL_DONT_CARE);
            S(GL_FASTEST);
            S(GL_NICEST);
            S(GL_LIGHT0);
            S(GL_LIGHT1);
            S(GL_LIGHT2);
            S(GL_LIGHT3);
            S(GL_LIGHT4);
            S(GL_LIGHT5);
            S(GL_LIGHT6);
            S(GL_LIGHT7);

            S(GL_AMBIENT);
            S(GL_DIFFUSE);
            S(GL_SPECULAR);
            S(GL_POSITION);
            S(GL_SPOT_DIRECTION);
            S(GL_SPOT_EXPONENT);
            S(GL_SPOT_CUTOFF);
            S(GL_CONSTANT_ATTENUATION);

            S(GL_COMPILE);
            S(GL_COMPILE_AND_EXECUTE);
            S(GL_CLEAR);
            S(GL_AND);
            S(GL_AND_REVERSE);
            S(GL_COPY);
            S(GL_AND_INVERTED);
            S(GL_NOOP);
            S(GL_XOR);
            S(GL_OR);
            S(GL_NOR);
            S(GL_EQUIV);
            S(GL_INVERT);
            S(GL_OR_REVERSE);
            S(GL_COPY_INVERTED);
            S(GL_OR_INVERTED);
            S(GL_NAND);
            S(GL_SET);

            S(GL_EMISSION);
            S(GL_SHININESS);
            S(GL_AMBIENT_AND_DIFFUSE);
            S(GL_COLOR_INDEXES);

            S(GL_MODELVIEW);
            S(GL_PROJECTION);
            S(GL_TEXTURE);

            S(GL_COLOR);
            S(GL_DEPTH);
            S(GL_STENCIL);

            S(GL_COLOR_INDEX);
            S(GL_STENCIL_INDEX);
            S(GL_DEPTH_COMPONENT);
            S(GL_RED);
            S(GL_GREEN);
            S(GL_BLUE);
            S(GL_ALPHA);
            S(GL_RGB);
            S(GL_RGBA);
            S(GL_LUMINANCE);
            S(GL_LUMINANCE_ALPHA);
            S(GL_BITMAP);

            S(GL_POINT);
            S(GL_LINE);
            S(GL_FILL);

            S(GL_RENDER);
            S(GL_FEEDBACK);
            S(GL_SELECT);

            S(GL_FLAT);
            S(GL_SMOOTH);
            S(GL_KEEP);
            S(GL_REPLACE);
            S(GL_INCR);
            S(GL_DECR);
            S(GL_INCR_WRAP_EXT);
            S(GL_DECR_WRAP_EXT);

            S(GL_VENDOR);
            S(GL_RENDERER);
            S(GL_VERSION);
            S(GL_EXTENSIONS);

                //S(GL_S);
            S(GL_T);
            S(GL_R);
            S(GL_Q);
            S(GL_MODULATE);
            S(GL_DECAL);

            S(GL_TEXTURE_ENV_MODE);
            S(GL_TEXTURE_ENV_COLOR);

            S(GL_TEXTURE_ENV);

            S(GL_EYE_LINEAR);
            S(GL_OBJECT_LINEAR);
            S(GL_SPHERE_MAP);

            S(GL_TEXTURE_GEN_MODE);
            S(GL_OBJECT_PLANE);
            S(GL_EYE_PLANE);

            S(GL_NEAREST);
            S(GL_LINEAR);

            S(GL_NEAREST_MIPMAP_NEAREST);
            S(GL_LINEAR_MIPMAP_NEAREST);
            S(GL_NEAREST_MIPMAP_LINEAR);
            S(GL_LINEAR_MIPMAP_LINEAR);

            S(GL_TEXTURE_MAG_FILTER);
            S(GL_TEXTURE_MIN_FILTER);
            S(GL_TEXTURE_WRAP_S);
            S(GL_TEXTURE_WRAP_T);
            S(GL_TEXTURE_WRAP_R);

            S(GL_CLAMP);
            S(GL_CLAMP_TO_EDGE);
            S(GL_REPEAT);

            S(GL_POLYGON_OFFSET_FACTOR);
            S(GL_POLYGON_OFFSET_UNITS);
            S(GL_POLYGON_OFFSET_POINT);
            S(GL_POLYGON_OFFSET_LINE);
            S(GL_POLYGON_OFFSET_FILL);
            S(GL_VERTEX_ARRAY);
            S(GL_NORMAL_ARRAY);
            S(GL_COLOR_ARRAY);
            S(GL_INDEX_ARRAY);
            S(GL_TEXTURE_COORD_ARRAY);
            S(GL_EDGE_FLAG_ARRAY);
            S(GL_VERTEX_ARRAY_SIZE);
            S(GL_VERTEX_ARRAY_TYPE);
            S(GL_VERTEX_ARRAY_STRIDE);
            S(GL_NORMAL_ARRAY_TYPE);
            S(GL_NORMAL_ARRAY_STRIDE);
            S(GL_COLOR_ARRAY_SIZE);
            S(GL_COLOR_ARRAY_TYPE);
            S(GL_COLOR_ARRAY_STRIDE);
            S(GL_INDEX_ARRAY_TYPE);
            S(GL_INDEX_ARRAY_STRIDE);

                //S(GL_VERTEX_ARRAY_EXT);
                //S(GL_NORMAL_ARRAY_EXT);
                //S(GL_COLOR_ARRAY_EXT);
                //S(GL_INDEX_ARRAY_EXT);
                //S(GL_TEXTURE_COORD_ARRAY_EXT);
                //S(GL_EDGE_FLAG_ARRAY_EXT);
                //S(GL_VERTEX_ARRAY_SIZE_EXT);
                //S(GL_VERTEX_ARRAY_TYPE_EXT);
                //S(GL_VERTEX_ARRAY_STRIDE_EXT);
            S(GL_VERTEX_ARRAY_COUNT_EXT);
                //S(GL_NORMAL_ARRAY_TYPE_EXT);
                //S(GL_NORMAL_ARRAY_STRIDE_EXT);
            S(GL_NORMAL_ARRAY_COUNT_EXT);
                //S(GL_COLOR_ARRAY_SIZE_EXT);
                //S(GL_COLOR_ARRAY_TYPE_EXT);
                //S(GL_COLOR_ARRAY_STRIDE_EXT);

            S(GL_COLOR_ARRAY_COUNT_EXT);
                //S(GL_INDEX_ARRAY_TYPE_EXT);
                //S(GL_INDEX_ARRAY_STRIDE_EXT);
            S(GL_INDEX_ARRAY_COUNT_EXT);
            S(GL_TEXTURE_COORD_ARRAY_SIZE_EXT);
            S(GL_TEXTURE_COORD_ARRAY_TYPE_EXT);
            S(GL_TEXTURE_COORD_ARRAY_STRIDE_EXT);
            S(GL_TEXTURE_COORD_ARRAY_COUNT_EXT);
            S(GL_EDGE_FLAG_ARRAY_STRIDE_EXT);
            S(GL_EDGE_FLAG_ARRAY_COUNT_EXT);
            S(GL_VERTEX_ARRAY_POINTER_EXT);
            S(GL_NORMAL_ARRAY_POINTER_EXT);
            S(GL_COLOR_ARRAY_POINTER_EXT);
            S(GL_INDEX_ARRAY_POINTER_EXT);
            S(GL_TEXTURE_COORD_ARRAY_POINTER_EXT);
            S(GL_EDGE_FLAG_ARRAY_POINTER_EXT);
            S(GL_PHONG_WIN);
            S(GL_PHONG_HINT_WIN);

            S(GL_FOG_SPECULAR_TEXTURE_WIN);

            S(GL_COLOR_LOGIC_OP);
            S(GL_COLOR_MATERIAL);
            S(GL_BLEND);
            S(GL_BLEND_DST);
            S(GL_BLEND_SRC);
            S(GL_ALPHA_TEST);
            S(GL_DEPTH_TEST);
            S(GL_NORMALIZE);
            S(GL_STENCIL_TEST);
            S(GL_POLYGON_STIPPLE);
            S(GL_POLYGON_SMOOTH);
            S(GL_LINE_STIPPLE);
            S(GL_AUTO_NORMAL);
            S(GL_CULL_FACE);
            S(GL_DITHER);
            S(GL_FOG);
            S(GL_INDEX_LOGIC_OP);
            S(GL_MAP1_COLOR_4);
            S(GL_MAP1_INDEX);
            S(GL_MAP1_NORMAL);
            S(GL_MAP1_TEXTURE_COORD_1);
            S(GL_MAP1_TEXTURE_COORD_2);
            S(GL_MAP1_TEXTURE_COORD_3);
            S(GL_MAP1_TEXTURE_COORD_4);
            S(GL_MAP1_VERTEX_3);
            S(GL_MAP1_VERTEX_4);
            S(GL_MAP2_COLOR_4);
            S(GL_MAP2_INDEX);
            S(GL_MAP2_NORMAL);
            S(GL_MAP2_TEXTURE_COORD_1);
            S(GL_MAP2_TEXTURE_COORD_2);
            S(GL_MAP2_TEXTURE_COORD_3);
            S(GL_MAP2_TEXTURE_COORD_4);
            S(GL_MAP2_VERTEX_3);
            S(GL_MAP2_VERTEX_4);
            S(GL_SCISSOR_TEST);
            S(GL_TEXTURE_1D);
            S(GL_TEXTURE_2D);
            S(GL_TEXTURE_3D);
            S(GL_TEXTURE_GEN_Q);
            S(GL_TEXTURE_GEN_R);
            S(GL_TEXTURE_GEN_S);
            S(GL_TEXTURE_GEN_T);
            S(GL_TEXTURE_BINDING_1D);
            S(GL_TEXTURE_BINDING_2D);
            S(GL_TEXTURE_BINDING_3D);

            S(GL_FLOAT_VEC2_ARB);
            S(GL_FLOAT_VEC3_ARB);
            S(GL_FLOAT_VEC4_ARB);
            S(GL_INT_VEC2_ARB);
            S(GL_INT_VEC3_ARB);
            S(GL_INT_VEC4_ARB);
            S(GL_BOOL_ARB);
            S(GL_BOOL_VEC2_ARB);
            S(GL_BOOL_VEC3_ARB);
            S(GL_BOOL_VEC4_ARB);
            S(GL_FLOAT_MAT2_ARB);
            S(GL_FLOAT_MAT3_ARB);
            S(GL_FLOAT_MAT4_ARB);
            S(GL_SHADER_OBJECT_ARB);

            S(GL_SAMPLER_1D_ARB);
            S(GL_SAMPLER_2D_ARB);
            S(GL_SAMPLER_3D_ARB);
            S(GL_SAMPLER_CUBE_ARB);
            S(GL_SAMPLER_1D_SHADOW_ARB);
            S(GL_SAMPLER_2D_SHADOW_ARB);
            S(GL_SAMPLER_2D_RECT_ARB);
            S(GL_SAMPLER_2D_RECT_SHADOW_ARB);
            S(GLX_TEXTURE_RECTANGLE_EXT);

                //S(GL_LOGIC_OP GL_INDEX_LOGIC_O);
                //S(GL_TEXTURE_COMPONENTS GL_TEXTURE_INTERNAL_FORMAT);

#undef S

            default: {
                static char x[12];
                sprintf(x, "?0x%x?", i);
                return x;
            }
        }
    }

} // namespace

