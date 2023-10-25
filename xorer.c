#include <stdio.h>

int main (int argc, char *argv[])
{
  FILE *in, *out;                   // - peremennie in i out - ukazateli na tip FILE,
				    //   kotorie budut ispolzovatsya dlya dostupa k failam
				    //   (dostup proishodit s ispolzovaniem std funciy)

  char *key;
  int byte;

  //proverka pravilnosti vizova programmi (kolichestvo argumentov)
  //:
  if (argc !=4) {
    printf ("Usage: xorer <key> <input_file> <output_file>\n");
    return 1;
  }

  //dalee vipolniaetsya proverka kazhdogo argumenta
  //:
  key = argv[1];        // - klyuchu prisvaivaem perviy argument

  if ((in = fopen(argv[2], "rb")) != NULL) {        // - proverka otkrilsya li
						    //   ishodnyi file
    if ((out = fopen(argv[3], "wb")) != NULL) {     // - proverka otkrilsya li
						    //   vihodnoi file

      while ((byte = getc(in)) != EOF)           //chitaem odin simvol iz vh.
						 //vhod. file
						 //i proveryaem ne yavlyaetsya
						 //li on koncom faila (EOF)
	  {
	if (!*key) key = argv[1];
	  byte ^= *(key++);
	putc(byte,out);
	  }

    fclose(out); }
  fclose(in); }

  return 0;
}
