#pragma once

using namespace System;

namespace PersonnesEtAdresses
{
	template<typename T>
	public ref class MappingSQL abstract
	{
	public:
		virtual String^ SelectById(int id) = 0;
		virtual String^ SelectAll() = 0;
		virtual String^ Update(T entity) = 0;
		virtual String^ Delete(int id) = 0;
		virtual String^ Insert(T entity) = 0;
	};
}
