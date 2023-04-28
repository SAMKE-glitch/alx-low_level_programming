/**
 * File: 100-elf_header.c
 * Auth: Brenan D Baraban
 */
#include "main.h"
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
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/** check_elf - checks if provided file is an elf file
 * @e_ident: pointer containing the elf file
 * Description: if the file is not an elf file exit code 98
 * Return: Nothing
 */
void check_elf(unsigned char *e_ident)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (e_ident[i] != 127 &&
				e_ident[i] != 'E' &&
				e_ident[i] != 'L' &&
				e_ident[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
				exit(98);
		}
	}
}
/**
 * print_magic - Prints the magic numbers of an ELF header.
 * @e_ident: a pointer to an array containing the elf ELF magic numbers
 *
 * Return: nothing
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:  ");

	for(i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
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
			printf("2's complement, little endian\n");
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
	printf("  Version:                     %d", 
		e_ident[EI_VERSION]);

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
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}
/**
 * print_abi - function prints the ABI version of ELF header
 * @e_ident: pointer  to array containing the ELF ABI version.
 * Return: Nothing
 */
void print_abi(unsigned char *e_ident)
{
	printf("ABI Version:                 %d\n",
		e_ident[EI_ABIVERSION]);
}
/**
 * print_type - function prints the type of an ELF header
 * @e_type: the ELF type
 * @e_ident: pointer to an array containing ELF class
 * Return: nothing
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
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
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
	}
}
/**
 * print_entry - function that prints entry point of ELF header
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
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}
/**
 * close_elf - function that closes an ELF File
 * @elf: fd of the ELF file
 *
 * Description: if fd can't be closed exit code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't clsoe the fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Displays infot cantained in the ELF header of ELF file
 * @argc: The number of arguments entered to the program
 * @argv: An array of pointers to the arguments
 *
 * Return: 0 on sucess
 *
 * Description: if file not ELF file or function fails exit code 98
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int s, m;

	s = open(argv[1], O_RDONLY);

	if (s == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cant read file %s\n", argv[1]);
		exit(98);
	}

	header = malloc(sizeof(Elf64_Ehdr));

	if (header == NULL)
	{
		close_elf(s);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	m = read(s, header, sizeof(Elf64_Ehdr));
	if (m == -1)
	{
		free(header);
		close_elf(s);
		dprintf(STDERR_FILENO, "Error: '%s': No such file\n", argv[1]);
		exit(98);
	}
	check_elf(header->e_ident);
	printf("ELF Header:.n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(s);
	return (0);
}
