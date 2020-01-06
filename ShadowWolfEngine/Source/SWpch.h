#pragma once

#ifdef SW_PLATFORM_WINDOWS
#include <Windows.h>
#endif

//std includes
#include <memory>
#include <vector>
#include <string>
#include <array>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <fstream>

//Engine includes
#include "CoreApplication/Core/Utilities/Base.h"
#include "CoreApplication/Core/Debug/Log.h"
#include "CoreApplication/Core/Events/Event.h"