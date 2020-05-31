workspace "PBPong"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
IncludeDir = {}
IncludeDir["SDL2"] = "PeanutButter/PeanutButter/thirdparty/SDL2-2.0.12/include"
IncludeDir["SDL2_Image"] = "PeanutButter/PeanutButter/thirdparty/SDL2_image-2.0.5/include"
IncludeDir["SDL2_ttf"] = "PeanutButter/PeanutButter/thirdparty/SDL2_ttf-2.0.15/include"

project "PeanutButter"
    location "PeanutButter/PeanutButter"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pbpch.h"
    pchsource "PeanutButter/PeanutButter/src/pbpch.h"
    
    files
	{
		"%{prj.name}/PeanutButter/src/**.h",
		"%{prj.name}/PeanutButter/src/**.cpp"
    }
    
    includedirs
	{
		"%{prj.name}/PeanutButter/src",
		"%{prj.name}/PeanutButter/thirdparty/spdlog/include",
		"%{IncludeDir.SDL2}",
		"%{IncludeDir.SDL2_Image}",
		"%{IncludeDir.SDL2_ttf}"
    }
    
    links 
	{
		"SDL2.lib",
		"SDL2main.lib",
		"SDL2_image.lib",
		"SDL2_ttf.lib"
    }
    
    filter "system:windows"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"PB_PLATFORM_WINDOWS",
			"PB_ENABLE_ASSERT"
		}

	filter "configurations:Debug"
		defines "PB_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PB_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PB_DIST"
		optimize "On"

project "PBPong"
    location "PBPong"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files
    {
        "%{prj.name}/PBPong/src/**.h",
        "%{prj.name}/PBPong/src/**.cpp"
    }

    includedirs 
    {
        "PeanutButter/PeanutButter/thirdparty/spdlog/include",
        "PeanutButter/PeanutButter/src",
        "%{IncludeDir.SDL2}",
		"%{IncludeDir.SDL2_Image}",
		"%{IncludeDir.SDL2_ttf}"
    }

    links
    {
        "PeanutButter"
    }

    filter "system:windows"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"PB_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "PB_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PB_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PB_DIST"
		optimize "On"