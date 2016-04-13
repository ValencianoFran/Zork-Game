#ifndef STRUCT__
#define STRUCT__

template<class TYPE>
class Vector
{
private:

	TYPE* vec = nullptr;
	unsigned int capacity = 10;
	unsigned int num_elements = 0;

public:

	//CONSTRUCTOR
	Vector()
	{
		vec = new TYPE[10];
	}

	//COPY
	Vector(const Vector& other)
	{

		num_elements = other.num_elements;
		capacity = other.capacity;
		vec = new TYPE[other.num_elements];
		if (other.num_elements > 0)
		{
			for (unsigned int i = 0; i < other.num_elements; i++)
			{
				*(vec + i) = *(other.vec + i);
			}
		}
	}

	//PUSH BACK
	void push_back(const TYPE& element)
	{
		if (capacity == num_elements)
		{
			TYPE* temp = nullptr;
			capacity *= 2;
			temp = new TYPE[capacity];

			for (unsigned int i = 0; i < num_elements; i++)
			{
				*(temp + i) = *(vec + i);
			}
			delete[] vec;
			vec = temp;
		}

		*(vec + num_elements++) = element;
	}

	//PUSH FRONT
	void push_front(const TYPE& element)
	{
		TYPE* temp = nullptr;
		if (capacity == num_elements)
		{
			capacity *= 2;
		}
		temp = new TYPE[capacity];
		for (unsigned int i = 0; i < num_elements; i++)
		{
			*(temp + i + 1) = *(vec + i);
		}
		delete[] vec;
		vec = temp;
		*(vec) = element;
	}

	//[]
	TYPE operator[](const TYPE& number) const
	{
		return vec[number];
	}

	//v[5] = 0

	//EMPTY(?
	bool empty()
	{
		return num_elements == 0;
	}

	//CLEAN
	void clean()
	{
		num_elements = 0;
	}

	//SIZE
	TYPE size()
	{
		return num_elements;
	}

	//CAPACITY
	TYPE capacity()
	{
		return capacity;
	}

	//POP BACK
	void pop_back()
	{
		if (num_elements != 0)
		{
			num_elements--;
		}
	}

	//SHRINK TO FIT
	void shrink_to_fit()
	{
		if (capacity > num_elements)
		{
			TYPE* temp;
			capacity = num_elements;
			temp = new TYPE[capacity];
			vec = temp;
		}
	}

	//DESTRUCTOR
	~Vector()
	{
		delete[] vec;
	}

};



#endif