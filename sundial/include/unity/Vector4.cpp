#include "Vector4.h"

const float     Vector4f::infinity = std::numeric_limits<float>::infinity();
const Vector4f  Vector4f::infinityVec = Vector4f(std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity());

const Vector4f  Vector4f::zero = Vector4f(0, 0, 0, 0);
const Vector4f  Vector4f::one = Vector4f(1, 1, 1, 1);

Vector3f Vector4f::operator*( Vector3f value ) {
	float x = this->x * 2.f;
	float y = this->y * 2.f;
	float z = this->z * 2.f;
	float xx = this->x * x;
	float yy = this->y * y;
	float zz = this->z * z;
	float xy = this->x * y;
	float xz = this->x * z;
	float yz = this->y * z;
	float wx = this->w * x;
	float wy = this->w * y;
	float wz = this->w * z;

	Vector3f result;
	result.x = ( 1.f - ( yy + zz ) ) * value.x + ( xy - wz ) * value.y + ( xz + wy ) * value.z;
	result.y = ( xy + wz ) * value.x + ( 1.0f - ( xx + zz ) ) * value.y + ( yz - wx ) * value.z;
	result.z = ( xz - wy ) * value.x + ( yz + wx ) * value.y + ( 1.0f - ( xx + yy ) ) * value.z;

	return result;
}