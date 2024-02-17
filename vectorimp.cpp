#include<iostream>
#include<algorithm>
// implementation of the Vector 
 class vectorClass {


   private:
	// arr is the integer pointer
	// which stores the address of our vecto
	//row pointer to array
	int * arr;

	// capacity is the total storage
	// capacity of the vector
	// MAXIMAL COUNTS OF ELEMENTS
	int capacity;

	// size is the number of elements
	// currently present in the vector
	// count of current elements
	int size;

   public:
	// Default constructor to initialise
	// an initial capacity of 1 element and
	// allocating storage using dynamic allocation
	vectorClass()//constructor
	{
		arr = new int[1];
		capacity = 1;
		size = 0;
	}
	//parametric ctor
	vectorClass (int cap) : capacity{cap} {
	  arr =  new int[cap];
          size = cap/2;
	}
	// destructor to deallocate storage allocated by dynamic
	// allocation to prevent memory leak
	~vectorClass() { 
		delete[] arr;
	       arr = nullptr;//?	
	}

	// Function to add an element at the last
	void push_back(int  data)
	{

		// if the number of elements is equal to the
		// capacity, that means we don't have space to
		// accommodate more elements. We need to double the
		// capacity
		if (size == capacity) {
			int* temp = new int[2 * capacity];

			// copying old array elements to new array(temprory array)
			for (int i = 0; i < size; i++) {
				temp[i] = arr[i];
			}
			// deleting previous array
			delete[] arr;
			capacity *= 2;//double old capacity
			arr = temp;//naxkin cucichy dnum enq nor zangvaci vra
		}

		// Inserting data
		arr[size] = data;
		size++;
     	}
	void resize() {
	                if (size  == capacity) {
                        int* temp = new int[2 * capacity];

                        // copying old array elements to new array,jamanakavor array
                        for (int i = 0; i < size; i++) {
                                temp[i] = arr[i];
                        }

                        // deleting previous array
                        delete[] arr;
                         capacity *= 2;//naxkiny krknapatkum enq
                        arr = temp;//naxkin cucichy dnum enq nor zangvaci vra
                }

	}
          void reserve(int  newCapacity) {
               if (newCapacity != capacity) {
                 // Allocate new memory
               int* newData = new int[newCapacity];

                 // Copy elements from old memory to new memory
               for (int i = 0; i < size; ++i) {
                     newData[i] = arr[i];
                }

                // Release old memory
                delete[] arr;

                // Update data pointer and capacity
               arr = newData;
                capacity = newCapacity;
        }
    }


	// function to add element at any index
	void insert(int data, int index)
	{    
		if (index < 0 || index >= size) {
                       std::cout << "invaild index :" << std:: endl;
                      return;
                    }
		if (size == capacity) {
                    resize(); 
		}
		
    	for (int i = size ; i > index; --i) {
                     arr[i] = arr[i - 1];
		     }
		arr[index] = data;
		++size;
	
	}
     // Push an element to the front of the vector
    void push_front(const int& value) {
           if (size == capacity) {
              // Double the capacity if needed
             if(capacity == 0) 
		     capacity *=2;
	     reserve(capacity);
	   }
 
           // Shift existing elements to the right
          for (int i = size; i > 0; --i) {
              arr[i] = arr[i - 1];
           }

          //  Add the new element at the front
           arr[0] = value;

           // Increment the size
            ++size;
    }

   //removes element in specified value
    void remove(int value) {
          int newIndex = 0;
          for (int i = 0; i < size; ++i) {
              if (arr[i] != value ) {
                arr[newIndex++] = arr[i];
          }
       }
        size = newIndex;
     }

	// function to extract element at any index
	int  get(int index)
	{
		// if index is within the range
		if (index < size)
			return arr[index];
		// if index is not within range
		return -1;
	}
        int* data() {
	    return arr;
	}
	// function to delete last element
	void pop_back()
       	{ 
		size--; 
	}

	void pop_front() {
	     
		if (!empty()) {
		
		   for (int i = 0;i < size - 1;++i) {
		      arr[i] = arr[i +1];
		   }
		  }
		size--;
	}
	
        
        //remove element at specified position
	void removee(int position) {
           if (position >= 0 && position < size) {
              for (size_t i = position; i < size - 1; ++i) {
                 arr[i] = arr[i + 1];
               }
              --size;
           }
        }
	
	int& front() {
	   return arr[0];
	}

	int & back() {
	   return arr[size -1];
	}
        //reduces the capacity of the vector to fit its size.
        void shrinkToFit() {
            if (size < capacity) {
              reserve(size);
            }
        }
  
        int find(int value) {
            for (int i = 0; i < size; ++i) {
               if (arr[i] == value) {
                 return i;
               }
            }
            return -1;
        }

    
        void unique() {
            for (int i = 0; i < size; ++i) {
               for (int j = i + 1; j < size;) {
                  if (arr[i] == arr[j]) {
                      removee(j);
                  } else {
                      ++j;
                    }
               }
            }
	}

       void swapp(vectorClass & other) {
          std::swap(arr,other.arr);
          std::swap(size,other.size);
	  std::swap(capacity,other.capacity);
       
       }
   
        void reverse() {
           for (size_t i = 0; i < size / 2; ++i) {
              int tmp = arr[i]; 
	      arr[i] = arr[size - 1 - i];
	      arr[size - 1 - i] = arr[i];
           }
        }        

	
	int sizee() const 
	{
	       	return size;
       	}

	// function to get capacity of the vector
	int getcapacity() const 
	{
	       	return capacity;
       	}

	// function to print array elements
	void print()
	{     
		for (int i = 0; i < size; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
	bool empty() 
	{
	  if (size == 0) {
	     return true;
	  }
	  else return false;
	}
	int at(int index) {
	      return arr[index]; 
	}
      void clear() {
         delete[]arr;
	 size = 0;
	 arr = nullptr;
      }
       int back() const { //return the last element
        if (size > 0) {
            return arr[size - 1];
        } else {
            // Handle the case when the vector is empty
            std::cout << "Vector is empty. Cannot access the last element." << std::endl;
            return -1;  // You may choose a different approach to handle this case
        }
    }
      //copy ctor
     vectorClass (const vectorClass& ob) {
	     size = ob.size;
	     capacity = ob.capacity;
             arr = new int[capacity];
	     for (int i = 0;i < size; ++i) {
	       arr[i] = ob.arr[i];
	     }
     }
         

};

int main()
{
      vectorClass v;
      int value = 30;
	
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	
       
	std::cout << "Vector size : " << v.sizee() << std::endl;
	std::cout << "Vector capacity : " << v.getcapacity() <<std:: endl;
	std::cout << "uzac index :" ;
	int index;
	std::cin >> index;	
        std:: cout << v.at(index) << std:: endl;
        std::cout << " Empty?" << v.empty() << std::endl;
	std::cout << "Vector elements : ";
	v.print();
        v.remove(value);
        std::cout << "AFTER REMOVE"<< std:: endl;
	std:: cout << " Vector elements : " << std:: endl;
	v.print();
        int indexx;
	std::cout << "Enter the changeable index :" ;
	std::cin >> indexx;
	int data;
	std::cout << "New data for this index :";
	std::cin >> data;
        v.insert(data,index);
	std::cout << "After updating  index" << std::endl;

	std::cout << "Vector elements : " << std::endl;
	v.print();
        v.push_front(13);
        v.print();
	v.pop_front();
        v.print();         

	return 0;
}
