#pragma once
#include <stdexcept>

template<typename T>
class nullable {
private:
	T value_;
	bool has_value_;
	
public:
	//--------------------------------------------------
	// Constructors
	//--------------------------------------------------
	nullable<T>() : has_value_(false) {}
	nullable<T>(T value) : value_(value), has_value_(true) {}
	nullable<T>(const nullable<T>& n_value) : value_(n_value.value_), has_value_(n_value.has_value_) {}

	//--------------------------------------------------
	// Functions
	//--------------------------------------------------
	T Get() const { if (!has_value_) throw std::runtime_error("Value is none."); return this->value_; }

	//--------------------------------------------------
	// Operator overloads
	//--------------------------------------------------
	// getter
	// Cast to bool type.
	explicit operator bool() const { return this->has_value_; }
	// Cast to T type.
	explicit operator T() const { if (!this->has_value_) std::runtime_error("value is none."); return this->value_; }

	// setter
	// Set null.
	nullable<T>& operator=(const std::nullptr_t npt) { has_value_ = false; return *this; }
	// Set T type value.
	nullable<T>& operator=(const T value) { value_ = value; has_value_ = true; return *this; }
	// Set nullable<T> type value.
	nullable<T>& operator=(const nullable<T>& n_value) { value_ = n_value.value_; has_value_ = n_value.has_value_; return *this; }
};
