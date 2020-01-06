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
#include "Core/Utilities/Base.h"
#include "Core/Debug/Log.h"
#include "Core/Events/Event.h"