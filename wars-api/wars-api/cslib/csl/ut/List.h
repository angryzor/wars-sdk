#pragma once

namespace csl::ut {
    struct List {
        struct Node {
            void* prev;
            void* next;
        };

        void* first;
        void* last;
        unsigned short count;
        unsigned short nodeOffset;
    };

    void List_Init(List* list, unsigned short nodeOffset);
    void List_Append(List* list, void* item);
    void List_Remove(List* list, void* item);
    void* List_GetNext(const List* list, const void* item);

	template<class T>
	class ListT : public List
	{
	public:
		class iterator
		{
			friend ListT;
			
		protected:
			ListT<T>* list{};
			T* curNode{};

		public:
			iterator(const ListT<T>* list, T* curNode) : list{ list }, curNode{ curNode }
			{
				
			}
			
			T* operator->() const
			{
				return curNode;
			}

			T& operator*() const
			{
				return *operator->();
			}
			
			friend bool operator==(const iterator& lhs, const iterator& rhs)
			{
				return lhs.curNode == rhs.curNode;
			}

			friend bool operator!=(const iterator& lhs, const iterator& rhs)
			{
				return lhs.curNode != rhs.curNode;
			}

			iterator& operator++()
			{
				curNode = static_cast<T*>(List_GetNext(list, curNode));
				return *this;
			}

			operator T* () const
			{
				return operator->();
			}
		};

		class const_iterator
		{
			friend ListT;

		protected:
			const ListT<T>* list{};
			T* curNode{};

		public:
			const_iterator(const ListT<T>* list, T* curNode) : list{ list }, curNode{ curNode }
			{

			}

			T* operator->() const
			{
				return curNode;
			}

			T& operator*() const
			{
				return *operator->();
			}

			friend bool operator==(const const_iterator& lhs, const const_iterator& rhs)
			{
				return lhs.curNode == rhs.curNode;
			}

			friend bool operator!=(const const_iterator& lhs, const const_iterator& rhs)
			{
				return lhs.curNode != rhs.curNode;
			}

			const_iterator& operator++()
			{
				curNode = static_cast<T*>(List_GetNext(list, curNode));
				return *this;
			}

			operator T*() const
			{
				return operator->();
			}
		};

		ListT(unsigned short nodeOffset)
		{
            List_Init(this, nodeOffset);
		}
		
		void push_back(T* pItem)
		{
			List_Append(this, pItem);
		}

		void erase(T* pItem)
		{
			List_Remove(this, pItem);
		}

		void clear()
		{
			while (size() > 0) {
                List_Remove(this, last);
            }
		}

		~ListT()
		{
			clear();
		}
		
		[[nodiscard]] iterator begin()
        {
            return iterator(this, static_cast<T*>(first));
        }

		[[nodiscard]] iterator end()
		{
			return iterator(this, 0);
		}

		[[nodiscard]] const_iterator begin() const
        {
            return const_iterator(this, static_cast<T*>(first));
        }

		[[nodiscard]] const_iterator end() const
		{
			return const_iterator(this, 0);
		}
		
		[[nodiscard]] size_t size() const {
            return count;
        }

		[[nodiscard]] T* front() const
		{
			if (!size())
				return nullptr;
			
			return begin();
		}
	};
}
