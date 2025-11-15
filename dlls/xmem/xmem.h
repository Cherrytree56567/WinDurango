#pragma once
#include <cstdint>
#include <windows.h>
#include <iostream>

void XMemAlloc(uint64_t size, uint64_t flags, uint8_t* callerInfo);
uint64_t XMemAllocatePhysicalPages(uint64_t flags, uint64_t* pageNum, int64_t pageArray);
void XMemCreateWin32Heap(uint64_t flags, uint64_t baseAddr);
void XMemFree(int64_t addr, uint64_t flags, uint64_t callerInfo);
uint32_t XMemFreePhysicalPages(uint64_t pageNum, int64_t page);
bool XMemGetPhysicalMemoryLayout(uint32_t* layout);
void XMemGetTitleHeap();
void XMemGetWin32HeapName(HANDLE heap, void* outBuffer, int64_t outSize, int64_t* outLength);
bool XMemGetWin32HeapStatistics(uint64_t flags, uint64_t* stats);
int XMemGetWorkingSetStatistics(uint32_t flags, int64_t* stats);
uint64_t XMemGetWriteWatch();
void XMemIsToolsMemAvailable();
int64_t XMemMapPhysicalPages(int64_t vaddrs, int64_t pages);
uint32_t XMemMapPhysicalPagesScatter(int64_t vaddrs, int64_t pages);
void XMemRegisterGraphicsMemoryConfiguration(uint64_t* param_1);
uint64_t XMemResetWriteWatch();
bool XMemResumeWriteWatch();
void XMemSetAllocationHooks(uint8_t* alloc, uint8_t* free);
void XMemSetOption(int* options);
void XMemSetWin32HeapName(HANDLE heap, void* name, uint64_t size);
void XMemSetWin32HeapTrackingHooks(uint64_t alloc, uint64_t realloc, uint64_t free);
int XMemTransferMemory(uint32_t type, int64_t size);
void XMemVirtualAlloc(uint64_t baseAddr, uint64_t size, uint32_t type, uint64_t flags, uint32_t prot);
uint64_t XMemVirtualQuery(uint64_t proc, uint64_t addr, uint64_t* buf);
int64_t* XMemAllocDefault(uint64_t size, uint64_t flags);
void XMemFreeDefault(int64_t* ptr,uint64_t flags);
uint64_t XMemGetAllocationHysteresis(uint32_t type, uint64_t heap);
uint64_t XMemGetAllocationStatistics(uint32_t type, bool heap, int* stats);
uint64_t XMemPreallocateFreeSpace(uint32_t type, uint64_t heap);
uint64_t XMemSetAllocationHysteresis(uint32_t type, uint64_t heap, int64_t size);
void XMemDumpMemoryStats(int64_t heap, uint64_t flags);
void XMemGetFreePageStatistics(uint64_t* stats);