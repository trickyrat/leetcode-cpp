#include "pch.h"

#include "../src/codec.h"
#include "../src/utils.h"

using namespace std;

class CodecFixture {
public:
  string node;
  string expected;

  CodecFixture(string node, string expected) : node(node), expected(expected){};
};

class CodecTest : public testing::TestWithParam<CodecFixture> {};

INSTANTIATE_TEST_CASE_P(CodecTestCases, CodecTest,
                        testing::Values(CodecFixture("1,2,3,null,null,4,5",
                                                     "1,2,3,null,null,4,5"),
                                        CodecFixture("", "")));

TEST_P(CodecTest, Test) {
  CodecFixture param = GetParam();
  TreeNode *root = Utils::generate_tree_node(param.node);
  Codec serializer, deserializer;
  TreeNode *actual = deserializer.deserialize(serializer.serialize(root));
  TreeNode *expected = Utils::generate_tree_node(param.expected);
  EXPECT_TRUE(Utils::is_same_tree(expected, actual));
}