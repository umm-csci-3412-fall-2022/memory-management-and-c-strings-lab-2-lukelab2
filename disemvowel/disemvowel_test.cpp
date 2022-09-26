#include <gtest/gtest.h>

#include "disemvowel.h"

TEST(Disemvowel, HandleEmptyString) {
  char *a = disemvowel((char*) "");
  ASSERT_STREQ("", a);
}

TEST(Disemvowel, HandleNoVowels) {
  char *a = disemvowel((char*) "pqrst");
  ASSERT_STREQ("pqrst", a);
  free(a);
}

TEST(Disemvowel, HandleOnlyVowels) {
  char *a = disemvowel((char*) "aeiouAEIOUOIEAuoiea");	
  ASSERT_STREQ("", a);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  char *a = disemvowel((char*) "Morris, Minnesota");
  ASSERT_STREQ("Mrrs, Mnnst",a);
  free(a);
}

TEST(Disemvowel, HandlePunctuation) {
  char *a = disemvowel((char*) "An (Unexplained) Elephant!");
  ASSERT_STREQ("n (nxplnd) lphnt!", a);
  free(a);
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  char *a = disemvowel(str);
  ASSERT_STREQ("xyz", a);

  free(str);
  free(a);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
