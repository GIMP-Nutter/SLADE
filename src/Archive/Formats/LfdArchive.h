
#ifndef __LFDARCHIVE_H__
#define __LFDARCHIVE_H__

#include "Archive/Archive.h"

class LfdArchive : public TreelessArchive
{
public:
	LfdArchive();
	~LfdArchive();

	// LFD specific
	uint32_t	getEntryOffset(ArchiveEntry* entry);
	void		setEntryOffset(ArchiveEntry* entry, uint32_t offset);

	// Opening/writing
	bool	open(MemChunk& mc) override;						// Open from MemChunk
	bool	write(MemChunk& mc, bool update = true) override;	// Write to MemChunk

	// Misc
	bool	loadEntryData(ArchiveEntry* entry) override;

	// Entry addition/removal
	ArchiveEntry*	addEntry(
						ArchiveEntry* entry,
						unsigned position = 0xFFFFFFFF,
						ArchiveTreeNode* dir = nullptr,
						bool copy = false
					) override;
	ArchiveEntry*	addEntry(ArchiveEntry* entry, string add_namespace, bool copy = false) override;

	// Entry modification
	bool	renameEntry(ArchiveEntry* entry, string name) override;

	// Static functions
	static bool isLfdArchive(MemChunk& mc);
	static bool isLfdArchive(string filename);
};

#endif//__LFDARCHIVE_H__
