#ifndef GVSTRUCT_H__
#define GVSTRUCT_H__
///
//Queue Family
struct QueueFamilyIndices
{
	std::optional<uint32_t> graphicsFamily;
	std::optional<uint32_t> presentFamily;

	bool isTakeData()
	{
		return graphicsFamily.has_value() && presentFamily.has_value();
	}
};
///

///
//Swap Chain
struct SwapChainSupportDetails
{
	VkSurfaceCapabilitiesKHR capabilities;
	std::vector<VkSurfaceFormatKHR> formats;
	std::vector<VkPresentModeKHR> presentModes;

	bool isTakeData()
	{
		return !formats.empty() && !presentModes.empty();
	}
};

///

///
//Vertex input description
struct Vertex 
{
    //glm::vec2 pos;
    
    ///
    //Depth Buffering
    glm::vec3 pos;
    ///
    
    glm::vec3 color;

    ///
    //Combined Image Sampler
    glm::vec2 texCoord;
    ///

    static VkVertexInputBindingDescription getBindingDescription() 
    {
        VkVertexInputBindingDescription bindingDescription = {};
        bindingDescription.binding = 0;
        bindingDescription.stride = sizeof(Vertex);
        bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

        return bindingDescription;
    }

	static std::array<VkVertexInputAttributeDescription, 3> getAttributeDescriptions()
	{
		std::array<VkVertexInputAttributeDescription, 3> attributeDescriptions = {};

		attributeDescriptions[0].binding = 0;
		attributeDescriptions[0].location = 0;
		attributeDescriptions[0].format = VK_FORMAT_R32G32B32_SFLOAT;
		attributeDescriptions[0].offset = offsetof(Vertex, pos);

		attributeDescriptions[1].binding = 0;
		attributeDescriptions[1].location = 1;
		attributeDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
		attributeDescriptions[1].offset = offsetof(Vertex, color);

		attributeDescriptions[2].binding = 0;
		attributeDescriptions[2].location = 2;
		attributeDescriptions[2].format = VK_FORMAT_R32G32_SFLOAT;
		attributeDescriptions[2].offset = offsetof(Vertex, texCoord);

		return attributeDescriptions;
	}
};

///
//Shader Struct = 'Uniform'
//binding
struct UniformBufferObject {
    glm::mat4 world;
    glm::mat4 view;
    glm::mat4 proj;
};

const std::vector<Vertex> rectangle = {
    {{-0.5f, 0.5f, 0.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f}},
    {{0.5f, 0.5f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}},
    {{0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 1.0f}},
    {{-0.5f, -0.5f, 0.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}}
};

const std::vector<uint16_t> rectIndices = {
    2, 1, 0, 0, 3, 2
};

const std::vector<Vertex> vertices = {
    {{-0.5f, -0.5f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
    {{0.5f, -0.5f, 0.0f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},
    {{0.5f, 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
    {{-0.5f, 0.5f, 0.0f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}},

    {{-0.5f, -0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
    {{0.5f, -0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},
    {{0.5f, 0.5f, -0.5f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
    {{-0.5f, 0.5f, -0.5f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}}
};

const std::vector<uint16_t> indices = {
    0, 1, 2, 2, 3, 0,
    4, 5, 6, 6, 7, 4
};
///


static VkApplicationInfo GetApplicationInfo(char* _applicationName, char* _enginName, int _appMajorVersion, int _appMinorVersion, int _appPatchVersion, int _engineMajorVersion, int _engineMinorVersion, int _enginePatchVersion)
{
	VkApplicationInfo VkInfo = {};

	VkInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	VkInfo.pApplicationName = _applicationName;
	VkInfo.applicationVersion = VK_MAKE_VERSION(_appMajorVersion, _appMinorVersion, _appPatchVersion);
	VkInfo.pEngineName = _enginName;
	VkInfo.engineVersion = VK_MAKE_VERSION(_engineMajorVersion, _engineMinorVersion, _enginePatchVersion);
	VkInfo.apiVersion = VK_API_VERSION_1_0;

	return VkInfo;
}

static VkApplicationInfo GetApplicationInfo(const char* _applicationName, const char* _enginName, int _appMajorVersion, int _appMinorVersion, int _appPatchVersion, int _engineMajorVersion, int _engineMinorVersion, int _enginePatchVersion)
{
	VkApplicationInfo VkInfo = {};

	VkInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	VkInfo.pApplicationName = _applicationName;
	VkInfo.applicationVersion = VK_MAKE_VERSION(_appMajorVersion, _appMinorVersion, _appPatchVersion);
	VkInfo.pEngineName = _enginName;
	VkInfo.engineVersion = VK_MAKE_VERSION(_engineMajorVersion, _engineMinorVersion, _enginePatchVersion);
	VkInfo.apiVersion = VK_API_VERSION_1_0;

	return VkInfo;
}

///
//Custom
struct BufferFormat
{
    uint32_t BufferType = 0;
    uint32_t ImageType = 0;
};
///
#endif