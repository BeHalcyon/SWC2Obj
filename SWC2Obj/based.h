#pragma once
#include <iostream>
#include <vector>

class Vertex
{
public:
	int					current_id;
	int					point_type;
	double				x, y, z;
	double				radius;
	int					previous_id;
	int					index;
	int					degree = 0;
	bool				is_visited = false;
};

class Path
{
public:
	int					path_type;
	std::vector<Vertex> path;
};

template<typename T>
class Vec3D
{
public:
	T x, y, z;

	friend std::ostream& operator << (std::ostream& output, const Vec3D<T>& i)
	{
		output << "[" << i.x <<", "<< i.y << ", " << i.z << "]" << std::endl;
		return output;
	}
	Vec3D<T>& operator /= (Vec3D<T>& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		return *this;
	}
	Vec3D<T>& operator *= (Vec3D<T>& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	}
	Vec3D<T> operator-(Vec3D<T>& b)
	{
		Vec3D<T> c = { static_cast<T>(x - b.x), static_cast<T>(y - b.y), static_cast<T>(z - b.z) };
		return c;
	}
	Vec3D<T> normalized()
	{
		auto d = sqrt((x* x + y * y + z * z)*1.0);
		Vec3D<T> c = {static_cast<T>(x / d), static_cast<T>(y / d), static_cast<T>(z / d)};
		return c;
	}
	double length()
	{
		return sqrt((x * x + y * y + z * z) * 1.0);
	}
	Vec3D<T> operator*(double a)
	{
		Vec3D<T> c = { static_cast<T>(x * a), static_cast<T>(y * a), static_cast<T>(z * a) };
		return c;
	}
	Vec3D<T> operator+(Vec3D<T>& a)
	{
		Vec3D<T> c = { static_cast<T>(x + a.x), static_cast<T>(y + a.y), static_cast<T>(z + a.z) };
		return c;
	}
	Vec3D<T> operator+(T a)
	{
		Vec3D<T> c = { static_cast<T>(x + a), static_cast<T>(y + a), static_cast<T>(z + a) };
		return c;
	}
	Vec3D<T> operator-(T a)
	{
		Vec3D<T> c = { static_cast<T>(x - a), static_cast<T>(y - a), static_cast<T>(z - a) };
		return c;
	}
	Vec3D<T>& operator-=(Vec3D<T>& a)
	{
		x -= a.x;
		y -= a.y;
		z -= a.z;
		return *this;
	}
};
//class Vec3I
//{
//public:
//	int x, y, z;
//	friend std::ostream& operator << (std::ostream& output, const Vec3I& i)
//	{
//		output << "[" << i.x << ", " << i.y << ", " << i.z << "]" << std::endl;
//		return output;
//	}
//};