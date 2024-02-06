// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/components/pinhole_projection.fbs".

#pragma once

#include "../datatypes/mat3x3.hpp"
#include "../result.hpp"

#include <array>
#include <cstdint>
#include <memory>

namespace arrow {
    class Array;
    class DataType;
    class FixedSizeListBuilder;
} // namespace arrow

namespace rerun::components {
    /// **Component**: Camera projection, from image coordinates to view coordinates.
    ///
    /// Child from parent.
    /// Image coordinates from camera view coordinates.
    ///
    /// Example:
    /// ```text
    /// 1496.1     0.0  980.5
    ///    0.0  1496.1  744.5
    ///    0.0     0.0    1.0
    /// ```
    struct PinholeProjection {
        rerun::datatypes::Mat3x3 image_from_camera;

      public:
        // Extensions to generated type defined in 'pinhole_projection_ext.cpp'

        /// Construct a new 3x3 pinhole matrix from a pointer to 9 floats (in row major order).
        static PinholeProjection from_mat3x3(const float* elements) {
            return PinholeProjection(rerun::datatypes::Mat3x3(elements));
        }

      public:
        PinholeProjection() = default;

        PinholeProjection(rerun::datatypes::Mat3x3 image_from_camera_)
            : image_from_camera(image_from_camera_) {}

        PinholeProjection& operator=(rerun::datatypes::Mat3x3 image_from_camera_) {
            image_from_camera = image_from_camera_;
            return *this;
        }

        PinholeProjection(std::array<float, 9> flat_columns_) : image_from_camera(flat_columns_) {}

        PinholeProjection& operator=(std::array<float, 9> flat_columns_) {
            image_from_camera = flat_columns_;
            return *this;
        }

        /// Cast to the underlying Mat3x3 datatype
        operator rerun::datatypes::Mat3x3() const {
            return image_from_camera;
        }
    };
} // namespace rerun::components

namespace rerun {
    template <typename T>
    struct Loggable;

    /// \private
    template <>
    struct Loggable<components::PinholeProjection> {
        static constexpr const char Name[] = "rerun.components.PinholeProjection";

        /// Returns the arrow data type this type corresponds to.
        static const std::shared_ptr<arrow::DataType>& arrow_datatype();

        /// Fills an arrow array builder with an array of this type.
        static rerun::Error fill_arrow_array_builder(
            arrow::FixedSizeListBuilder* builder, const components::PinholeProjection* elements,
            size_t num_elements
        );

        /// Serializes an array of `rerun::components::PinholeProjection` into an arrow array.
        static Result<std::shared_ptr<arrow::Array>> to_arrow(
            const components::PinholeProjection* instances, size_t num_instances
        );
    };
} // namespace rerun
