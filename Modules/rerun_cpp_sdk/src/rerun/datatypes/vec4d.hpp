// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/datatypes/vec4d.fbs".

#pragma once

#include "../result.hpp"

#include <array>
#include <cstdint>
#include <memory>

namespace arrow {
    class Array;
    class DataType;
    class FixedSizeListBuilder;
} // namespace arrow

namespace rerun::datatypes {
    /// **Datatype**: A vector in 4D space.
    struct Vec4D {
        std::array<float, 4> xyzw;

      public:
        // Extensions to generated type defined in 'vec4d_ext.cpp'

        /// Construct Vec4D from x/y/z/w values.
        Vec4D(float x, float y, float z, float w) : xyzw{x, y, z, w} {}

        /// Construct Vec4D from x/y/z/w float pointer.
        explicit Vec4D(const float* xyzw_) : xyzw{xyzw_[0], xyzw_[1], xyzw_[2], xyzw_[3]} {}

        float x() const {
            return xyzw[0];
        }

        float y() const {
            return xyzw[1];
        }

        float z() const {
            return xyzw[2];
        }

        float w() const {
            return xyzw[3];
        }

      public:
        Vec4D() = default;

        Vec4D(std::array<float, 4> xyzw_) : xyzw(xyzw_) {}

        Vec4D& operator=(std::array<float, 4> xyzw_) {
            xyzw = xyzw_;
            return *this;
        }
    };
} // namespace rerun::datatypes

namespace rerun {
    template <typename T>
    struct Loggable;

    /// \private
    template <>
    struct Loggable<datatypes::Vec4D> {
        static constexpr const char Name[] = "rerun.datatypes.Vec4D";

        /// Returns the arrow data type this type corresponds to.
        static const std::shared_ptr<arrow::DataType>& arrow_datatype();

        /// Fills an arrow array builder with an array of this type.
        static rerun::Error fill_arrow_array_builder(
            arrow::FixedSizeListBuilder* builder, const datatypes::Vec4D* elements,
            size_t num_elements
        );

        /// Serializes an array of `rerun::datatypes::Vec4D` into an arrow array.
        static Result<std::shared_ptr<arrow::Array>> to_arrow(
            const datatypes::Vec4D* instances, size_t num_instances
        );
    };
} // namespace rerun
