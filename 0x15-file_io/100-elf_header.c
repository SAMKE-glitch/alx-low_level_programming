#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned int e_entry, unsigned char *e_ident);

int main(int argc, char argv[])
{
	int fd;
	char *buffer;
	ssize_t ch;

	fd = open(argv[1],  O_RDONLY | O_BINARY);

	if (fd == -1)
		return (-1);
	ch = read(fd, buffer, 1024);
	if (ch == -1)
	{
		return (-1);
	}
	check_elf(fd);
	close(fd);

	return(1);
}

/** check_elf - checks if provided file is an elf file
 * @e_ident: pointer containing the elf file
 * Description: if the file is not an elf file exit code 98
 * Return: Nothing
 */
void check_elf(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
				e_ident[index] != 'E' &&
				e_ident[index] != 'L' &&
				e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
				exit(98);
		}
	}
}
/**
 * void print_magic - Prints the magic numbers of an ELF header.
 * @e_ident: a pointer to an array containing the elf ELF magic numbers
 *
 * Return: nothing
 */
void print_magic(unsigned char *e_ident)
{
	int index;

	printf("  Magic:  ");

	for(index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);
		printf("\n");
	}
}
/**
 * print_class - print the class of an ELF header/file
 *
 * @e_ident: pointer to an array containing the ELF class
 *
 * Return: nothing
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:                                       ");

	switch(e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}
/**
 * print_data - prints the data of an ELF header
 * @e_ident: pointer to an array containing ELF data
 * Return: Nothing
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                                         ");

	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			print("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complent, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n>", e_ident[EI_CLASS]);
	}
}
/**
 * print_version - prints the version of an ELF header.
 * @e_ident: pointer to an array containing the ELF version
 * Return: nothing
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:                     %d", e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf("  (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}
/**
 * print_osabi - prints the OS/ABI of an ELF header
 * @e_ident: pointer to an array containing the ELF version
 * Return: nothing
 */
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                              ");

	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - Sytem V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			print("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}
/**
 * print_abi - prints the ABI version of an ELF header
 * @e_ident: pointer to an array containing the ELF ABI version.
 * Return: Nothing
 */
void print_abi(unsigned char *e_ident)
{
	printf("ABI Version:                 %d\n", e_ident[EI_ABIVERSION]);
}
/**
 * print_type - prints the type of an ELF header
 * @e_type: the ELF type
 * @e_ident: pointer to an array containing ELF class
 * Return: nothing
 */
void print_type(unsigned long int e_type, usigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("   Type:                         ");

	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE;
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
	}
}
/**
 * print_entry - Prints the entry point of an ELF header
 * @e_entry: The address of the entry point
 * @e_ident: pointer to an array containing the ELF class
 */
void print_entry(unsigned long int e_entry, unsigned  char *e_ident)
{
	printf("  Entry point address:           ");
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int) e_entry);
	else
		printf("%#lx\n", e_entry);
}
