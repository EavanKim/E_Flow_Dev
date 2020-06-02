#include "CVulkan_Core.h"

GV_SubPass::GV_SubPass(std::vector<uint8_t> _vertex, std::vector<uint8_t> _index)
	: m_VertexData(_vertex)
	, m_IndexData(_index)
{

}

void GV_SubPass::DestroyInstance(VkDevice _device)
{
	m_VertexData.clear();
	m_IndexData.clear();
}
