#pragma once

#include <vector>

template<typename TBase>
class ClassType
{
	public:
		template<typename T>
		static uint32_t GetType()
		{
			static const uint32_t m_Type = m_NextType++;
			return m_Type;
		};

	private:
		static uint32_t m_NextType;
};

template<typename TBase>
uint32_t ClassType<TBase>::m_NextType = 0;

template<typename TBase>
class Collection
{
	protected:
		std::vector<TBase*> m_Items;
		std::vector<uint64_t> m_Indexes;

	protected:
		template<typename T>
		uint64_t GetType()
		{
			return ClassType<TBase>::template GetType<T>();
		};

	public:
		template<typename T>
		void Add()
		{
			m_Items.push_back(new T);
			m_Indexes.push_back(GetType<T>());
		};

		template<typename T>
		T* Get()
		{
			uint64_t type = GetType<T>();
			uint64_t index_size = m_Indexes.size();
			uint64_t index;
			for (uint64_t cur = 0; cur < index_size; cur++) {
				index = m_Indexes.at(cur);
				if (index == type) {
					return (T*)m_Items.at(cur);
				}
			}
			return NULL;
		};

		template<typename T>
		bool Has()
		{
			return (this->Get<T>() != NULL);
		};

		std::vector<TBase*> GetAll()
		{
			return m_Items;
		};
};