#pragma once
#include "glew.h"
#include "Core/Core.h"
namespace Elion {


	struct Attribute {
		uint attribute = NULL;
		const char* AttributeName;
		uint Size;
		uint Offset;
		uint SizeOf;
		bool Normalized;
		int Value;

		Attribute(const char* attribute_name , uint size , bool normalized , uint sizeOf , uint offset , uint shader) :
			AttributeName(attribute_name),
			Size(size),
			Normalized(normalized),
			SizeOf(sizeOf),
			Offset(offset)
		{
			this->attribute = glGetAttribLocation(shader, attribute_name);
			glEnableVertexAttribArray(this->attribute);
			glVertexAttribPointer(this->attribute, size, GL_FLOAT, normalized, sizeOf * sizeof(float), (void*)(offset * sizeof(float)));
		}
		Attribute(const char* uniform_name, int value, uint shader) : 
			AttributeName(uniform_name),
			Value(value)
		    {
		     this->attribute = glGetAttribLocation(shader, uniform_name);
		    }
	};


	class ELION_API Attributes
	{
	private:
		std::vector<Attribute> attributeElements;

	public:
		Attributes(){}
		Attributes(const std::initializer_list<Attribute>& attributeE);

		inline std::vector<Attribute>& get_attr_elements() { return attributeElements; }

		std::vector<Attribute>::iterator begin() { return attributeElements.begin(); }
		std::vector<Attribute>::iterator end() { return attributeElements.end(); }
		std::vector<Attribute>::const_iterator begin() const { return attributeElements.begin(); }
		std::vector<Attribute>::const_iterator end() const { return attributeElements.end(); }

	};


}