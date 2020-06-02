#pragma once


class GV_SubPass : public GV_Instance
{
public:
	explicit GV_SubPass(std::vector<uint8_t> _vertex, std::vector<uint8_t> _index);

	// GV_Instance��(��) ���� ��ӵ�
	virtual void DestroyInstance(VkDevice _device) override;

protected:


private:
	std::vector<uint8_t> m_VertexData;
	std::vector<uint8_t> m_IndexData;
};

