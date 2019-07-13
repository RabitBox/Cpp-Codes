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
	inline nullable<T>& operator=(const std::nullptr_t npt) { has_value_ = false; return *this; }
	inline nullable<T>& operator=(const T value) { value_ = value; has_value_ = true; return *this; }
	inline nullable<T>& operator=(const nullable<T>& n_value) { value_ = n_value.value_; has_value_ = n_value.has_value_; return *this; }

	// getter
	inline explicit operator bool() const { return (*this).has_value_; }
	inline explicit operator T() const { if (!(*this).has_value_) std::runtime_error("value is none."); return (*this).value_; }
};