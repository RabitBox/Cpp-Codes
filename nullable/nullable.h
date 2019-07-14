#pragma once

template<typename T>
class nullable {
private:
	T value_;
	bool has_value_;
	
public:
	//--------------------------------------------------
	// constructors
	//--------------------------------------------------
	nullable<T>() : has_value_(false) {}
	nullable<T>(T value) : value_(value), has_value_(true) {}
	nullable<T>(const nullable<T>& n_value) : value_(n_value.value_), has_value_(n_value.has_value_) {}

	//--------------------------------------------------
	// operator overloads
	//--------------------------------------------------
	// setter
	// Set null.
	inline nullable<T>& operator=(const std::nullptr_t npt) { has_value_ = false; return *this; }
	// Set T type value.
	inline nullable<T>& operator=(const T value) { value_ = value; has_value_ = true; return *this; }
	// Set nullable<T> type value.
	inline nullable<T>& operator=(const nullable<T>& n_value) { value_ = n_value.value_; has_value_ = n_value.has_value_; return *this; }

	// getter
	// Cast to bool type.
	inline explicit operator bool() const { return (*this).has_value_; }
	// Cast to T type.
	inline explicit operator T() const { if (!(*this).has_value_) std::runtime_error("value is none."); return (*this).value_; }
};
