#pragma once
#include <vector>
#include <stdexcept>
 
namespace util
{
	template <typename KeyType, typename ValueType>
	class Map
	{
	public:
		class Wrapper //nested class
		{
		public:
			operator ValueType&();
			ValueType *operator&();
			const ValueType& operator=(const ValueType& rValue);

		private:
			Wrapper(Map &map, const KeyType &key);
			Wrapper(const Wrapper &value);

			Map &map;
			KeyType key;
			ValueType *value;

			friend class Map;
		};

		Wrapper operator[](const KeyType& key);
		unsigned size();

	private:
		std::vector<KeyType> keys;
		std::vector<ValueType> values;

		ValueType* find(const KeyType &key);
		ValueType* set(const KeyType &key, const ValueType &value);
	};


	template <typename KeyType, typename ValueType>
	typename Map<KeyType, ValueType>::Wrapper Map<KeyType, ValueType>::operator[](const KeyType& key)
	{
		//return a Wrapper object that has a reference to this Map and the key that was passed in
		Wrapper result(*this, key);
		return result;
	}

	template <typename KeyType, typename ValueType>
	unsigned Map<KeyType, ValueType>::size()
	{
		return keys.size();
	}

	template <typename KeyType, typename ValueType>
	ValueType* Map<KeyType, ValueType>::find(const KeyType &key)
	{
		ValueType* result = NULL;

		for (int i = 0; i < keys.size(); i++)
		{
			if (keys[i] == key)
			{
				result = &(values[i]);
			}
		}
		return result;
	}

	template <typename KeyType, typename ValueType>
	ValueType* Map<KeyType, ValueType>::set(const KeyType &key, const ValueType &value)
	{
		ValueType* valueInMap = find(key);

		if (valueInMap != NULL)
		{
			*valueInMap = value;
		}
		else
		{
			keys.push_back(key);
			values.push_back(value);
		}

		valueInMap = find(key);
		return valueInMap;
	}

	/*=========================================================================*/

	template <typename KeyType, typename ValueType>
	Map<KeyType, ValueType>::Wrapper::Wrapper(Map &map, const KeyType &key) : map(map), key(key)
	{
		//set value to point to key's corresponding pair in the map (or NULL)
		value = map.find(key);
	}

	//copy constructor
	template <typename KeyType, typename ValueType>
	Map<KeyType, ValueType>::Wrapper::Wrapper(const Wrapper &rValue) : map(rValue.map), key(rValue.key)
	{
		value = map.find(key);
	}

	//conversion operator, Wrapper -> ValueType
	template <typename KeyType, typename ValueType>
	Map<KeyType,ValueType>::Wrapper::operator ValueType&()
	{
		if (value == NULL)
		{
			throw std::range_error("Key not found in map");
		}
		return *value;
	}

	template <typename KeyType, typename ValueType>
	ValueType* Map<KeyType,ValueType>::Wrapper::operator&()
	{
		if (value == NULL)
		{
			throw std::range_error("Key not found in map");
		}
		return value;
	}

	//assignment operator.  This is used when a wrapper is the l-value in an assignment 
	//and the r-value is of type ValueType
	template <typename KeyType, typename ValueType>
	const ValueType& Map<KeyType, ValueType>::Wrapper::operator=(const ValueType &rValue)
	{
		map.set(key, rValue);
		return rValue;
	}
}