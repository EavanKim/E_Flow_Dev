#ifndef ARRAY_HPP__
#define ARRAY_HPP__

namespace util
{
	class E_Array 
	{
	public:
		typedef std::vector<Vector> ContainerType;
		typedef typename ContainerType::iterator Iterator;
		typedef typename ContainerType::const_iterator ConstIterator;

		E_Array();

		explicit E_Array(size_t _size, const Vector& _initVal = Vector());
		
		E_Array(const std::initializer_list<Vector>& _lst);

		E_Array(const E_Array& _other);

		E_Array(E_Array&& _other);

		void set(const Vector& _value);

		void set(const E_Array& _other);

		void set(const std::initializer_list<Vector>& _lst);

		void clear();

		void resize(size_t _size, const Vector& _initVal = Vector());

		Vector& at(size_t _Index);

		const Vector& at(size_t _Index) const;

		size_t size() const;

		Vector* data();

		const Vector* const data() const;

		Iterator begin();

		ConstIterator begin() const;

		Iterator end();

		ConstIterator end() const;

		//ArrayAccessor accessor();

		//ConstArrayAccessor constAccessor() const;

		void swap(E_Array& _other);

		void append(const Vector& _newVal);

		void append(const E_Array& _other);

		template <typename Callback>
		void forEach(Callback _func) const;

		template <typename Callback>
		void forEachIndex(Callback _func) const;

		template <typename Callback>
		void parallelForEach(Callback _func) const;

		template <typename Callback>
		void parallelForEachIndex(Callback func) const;

		Vector& operator[] (size_t _Index);

		const Vector& operator[] (size_t _Index) const;

		E_Array& operator= (const Vector& _other);

		E_Array& operator= (const E_Array& _other);

		E_Array& operator= (E_Array&& _other);

		E_Array& operator= (const std::initializer_list<Vector>& _lst);

		//operator ArrayAccess();

		//operator ConstArrayAccessor() const;

	private:
		ContainerType m_Data;
	};
}

#endif
