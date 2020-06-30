#pragma once
class CE_Builder
{
public:
	CE_Builder() = delete;
	virtual ~CE_Builder() = delete;

	virtual CE_Builder Build() = 0;

private:
	
};
