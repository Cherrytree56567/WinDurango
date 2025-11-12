#ifndef PCH_H
#define PCH_H

#include "framework.h"
#include "kernelx.h"

#include "../../Thirdparty/Detours/src/detours.h"
#include "CoreWindowWrapperX.h"
#include "ICoreWindowX.h"

#include <cstdint>
#include <cstdlib>
#include <intrin.h>
#include <roapi.h>
#include <string>
#include <string_view>
#include <winternl.h>
#include <wrl.h>
// #include <__msvc_string_view.hpp>
#include <ntstatus.h>

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;

#endif // PCH_H