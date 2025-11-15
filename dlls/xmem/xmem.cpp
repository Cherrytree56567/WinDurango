#include "xmem.h"

void XMemAlloc(uint64_t size, uint64_t flags, uint8_t* callerInfo) {
    std::cout << "Unimplemented - XMemAlloc!\n";
}

uint64_t XMemAllocatePhysicalPages(uint64_t flags, uint64_t* pageNum, int64_t pageArray) {
    std::cout << "Unimplemented - XMemAlloc!\n";
    return 0;
}

void XMemCreateWin32Heap(uint64_t flags, uint64_t baseAddr) {
    std::cout << "Unimplemented - XMemAlloc!\n";
}

void XMemFree(int64_t addr, uint64_t flags, uint64_t callerInfo) {
    std::cout << "Unimplemented - XMemAlloc!\n";
}

uint32_t XMemFreePhysicalPages(uint64_t pageNum, int64_t page) {
    std::cout << "Unimplemented - XMemAlloc!\n";
    return 0;
}

bool XMemGetPhysicalMemoryLayout(uint32_t* layout) {
    std::cout << "Unimplemented - XMemAlloc!\n";
    return true;
}

void XMemGetTitleHeap() {
    std::cout << "Unimplemented - XMemAlloc!\n";
}

void XMemGetWin32HeapName(HANDLE heap, void* outBuffer, int64_t outSize, int64_t* outLength) {
    std::cout << "Unimplemented - XMemAlloc!\n";
}

bool XMemGetWin32HeapStatistics(uint64_t flags, uint64_t* stats) {
    std::cout << "Unimplemented - XMemAlloc!\n";
    return true;
}

int XMemGetWorkingSetStatistics(uint32_t flags, int64_t* stats) {
    std::cout << "Unimplemented - XMemAlloc!\n";
    return 0;
}

uint64_t XMemGetWriteWatch() {
    std::cout << "Unimplemented - XMemAlloc!\n";
    return 0;
}

void XMemIsToolsMemAvailable() {
    std::cout << "Unimplemented - XMemAlloc!\n";
}

int64_t XMemMapPhysicalPages(int64_t vaddrs, int64_t pages) {
    std::cout << "Unimplemented - XMemAlloc!\n";
    return 0;
}

uint32_t XMemMapPhysicalPagesScatter(int64_t vaddrs, int64_t pages) {
    std::cout << "Unimplemented - XMemAlloc!\n";
    return 0;
}

uint64_t XMemResetWriteWatch() {
    std::cout << "Unimplemented - XMemAlloc!\n";
    return 0;
}

bool XMemResumeWriteWatch() {
    std::cout << "Unimplemented - XMemAlloc!\n";
    return true;
}

void XMemSetAllocationHooks(uint8_t* alloc, uint8_t* free) {
    std::cout << "Unimplemented - XMemAlloc!\n";
}

void XMemSetOption(int* options) {
    std::cout << "Unimplemented - XMemAlloc!\n";
}

void XMemSetWin32HeapName(HANDLE heap, void* name, uint64_t size) {
    std::cout << "Unimplemented - XMemAlloc!\n";
}

void XMemSetWin32HeapTrackingHooks(uint64_t alloc, uint64_t realloc, uint64_t free) {
    std::cout << "Unimplemented - XMemAlloc!\n";
}

int XMemTransferMemory(uint32_t type, int64_t size) {
    std::cout << "Unimplemented - XMemAlloc!\n";
    return 0;
}

void XMemVirtualAlloc(uint64_t baseAddr, uint64_t size, uint32_t type, uint64_t flags, uint32_t prot) {
    std::cout << "Unimplemented - XMemAlloc!\n";
}

uint64_t XMemVirtualQuery(uint64_t proc, uint64_t addr, uint64_t* buf) {
    std::cout << "Unimplemented - XMemAlloc!\n";
    return 0;
}

void XMemRegisterGraphicsMemoryConfiguration(uint64_t* param_1) {
    std::cout << "Unimplemented - XMemAlloc!\n";
}

int64_t* XMemAllocDefault(uint64_t size, uint64_t flags) {
    std::cout << "Unimplemented - XMemAlloc!\n";
    return 0;
}

void XMemFreeDefault(int64_t* ptr, uint64_t flags) {
    std::cout << "Unimplemented - XMemAlloc!\n";
}

uint64_t XMemGetAllocationHysteresis(uint32_t type, uint64_t heap) {
    std::cout << "Unimplemented - XMemAlloc!\n";
    return 0;
}

uint64_t XMemGetAllocationStatistics(uint32_t type, bool heap, int* stats) {
    std::cout << "Unimplemented - XMemAlloc!\n";
    return 0;
}

uint64_t XMemPreallocateFreeSpace(uint32_t type, uint64_t heap) {
    std::cout << "Unimplemented - XMemAlloc!\n";
    return 0;
}

uint64_t XMemSetAllocationHysteresis(uint32_t type, uint64_t heap, int64_t size) {
    std::cout << "Unimplemented - XMemAlloc!\n";
    return 0;
}

void XMemDumpMemoryStats(int64_t heap, uint64_t flags) {
    std::cout << "Unimplemented - XMemAlloc!\n";
}

void XMemGetFreePageStatistics(uint64_t* stats) {
    std::cout << "Unimplemented - XMemAlloc!\n";
}