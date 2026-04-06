#include <gtest/gtest.h>
#include "Automata.h"
TEST(AutomataTest, test1) {
  Automata automata;
  EXPECT_EQ(automata.getState(), OFF);
}
TEST(AutomataTest, test2) {
  Automata automata;
  automata.on();
  EXPECT_EQ(automata.getState(), WAIT);
}
TEST(AutomataTest, test3) {
  Automata automata;
  automata.on();
  automata.off();
  EXPECT_EQ(automata.getState(), OFF);
}
TEST(AutomataTest, test4) {
  Automata automata;
  automata.on();
  automata.coin();
  EXPECT_EQ(automata.getState(), ACCEPT);
}
TEST(AutomataTest, test5) {
  Automata automata;
  automata.on();
  automata.coin();
  automata.choice();
  EXPECT_EQ(automata.getState(), CHECK);
}
TEST(AutomataTest, test6) {
  Automata automata;
  automata.on();
  for(int i = 0; i < 4; i++) {
      automata.coin();
  }
  EXPECT_TRUE(automata.check(1));
}
TEST(AutomataTest, test7) {
  Automata automata;
  automata.on();
  automata.coin();
  EXPECT_FALSE(automata.check(0));
}
TEST(AutomataTest, test8) {
  Automata automata;
  automata.on();
  automata.coin();
  automata.choice();
  automata.cancel();
  EXPECT_EQ(automata.getState(), WAIT);
}
TEST(AutomataTest, test9) {
  Automata automata;
  automata.on();
  for(int i = 0; i < 4; i++) {
      automata.coin();
  }
  automata.choice();
  EXPECT_TRUE(automata.check(1));
  automata.cook(1);
  EXPECT_EQ(automata.getState(), WAIT);
}
TEST(AutomataTest, test10) {
  Automata automata;
  automata.on();
  automata.coin();
  automata.coin();
  automata.choice();
  automata.cook(0);
  EXPECT_EQ(automata.getState(), CHECK);
}
