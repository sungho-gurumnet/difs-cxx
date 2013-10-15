# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# include <ndnboost/preprocessor/config/config.hpp>
#
# if NDNBOOST_PP_CONFIG_FLAGS() & NDNBOOST_PP_CONFIG_DMC()
#     include <ndnboost/preprocessor/detail/dmc/auto_rec.hpp>
# else
#
# ifndef NDNBOOST_PREPROCESSOR_DETAIL_AUTO_REC_HPP
# define NDNBOOST_PREPROCESSOR_DETAIL_AUTO_REC_HPP
#
# include <ndnboost/preprocessor/control/iif.hpp>
#
# /* NDNBOOST_PP_AUTO_REC */
#
# define NDNBOOST_PP_AUTO_REC(pred, n) NDNBOOST_PP_NODE_ENTRY_ ## n(pred)
#
# define NDNBOOST_PP_NODE_ENTRY_256(p) NDNBOOST_PP_NODE_128(p)(p)(p)(p)(p)(p)(p)(p)
# define NDNBOOST_PP_NODE_ENTRY_128(p) NDNBOOST_PP_NODE_64(p)(p)(p)(p)(p)(p)(p)
# define NDNBOOST_PP_NODE_ENTRY_64(p) NDNBOOST_PP_NODE_32(p)(p)(p)(p)(p)(p)
# define NDNBOOST_PP_NODE_ENTRY_32(p) NDNBOOST_PP_NODE_16(p)(p)(p)(p)(p)
# define NDNBOOST_PP_NODE_ENTRY_16(p) NDNBOOST_PP_NODE_8(p)(p)(p)(p)
# define NDNBOOST_PP_NODE_ENTRY_8(p) NDNBOOST_PP_NODE_4(p)(p)(p)
# define NDNBOOST_PP_NODE_ENTRY_4(p) NDNBOOST_PP_NODE_2(p)(p)
# define NDNBOOST_PP_NODE_ENTRY_2(p) NDNBOOST_PP_NODE_1(p)
#
# define NDNBOOST_PP_NODE_128(p) NDNBOOST_PP_IIF(p(128), NDNBOOST_PP_NODE_64, NDNBOOST_PP_NODE_192)
#    define NDNBOOST_PP_NODE_64(p) NDNBOOST_PP_IIF(p(64), NDNBOOST_PP_NODE_32, NDNBOOST_PP_NODE_96)
#        define NDNBOOST_PP_NODE_32(p) NDNBOOST_PP_IIF(p(32), NDNBOOST_PP_NODE_16, NDNBOOST_PP_NODE_48)
#            define NDNBOOST_PP_NODE_16(p) NDNBOOST_PP_IIF(p(16), NDNBOOST_PP_NODE_8, NDNBOOST_PP_NODE_24)
#                define NDNBOOST_PP_NODE_8(p) NDNBOOST_PP_IIF(p(8), NDNBOOST_PP_NODE_4, NDNBOOST_PP_NODE_12)
#                    define NDNBOOST_PP_NODE_4(p) NDNBOOST_PP_IIF(p(4), NDNBOOST_PP_NODE_2, NDNBOOST_PP_NODE_6)
#                        define NDNBOOST_PP_NODE_2(p) NDNBOOST_PP_IIF(p(2), NDNBOOST_PP_NODE_1, NDNBOOST_PP_NODE_3)
#                            define NDNBOOST_PP_NODE_1(p) NDNBOOST_PP_IIF(p(1), 1, 2)
#                            define NDNBOOST_PP_NODE_3(p) NDNBOOST_PP_IIF(p(3), 3, 4)
#                        define NDNBOOST_PP_NODE_6(p) NDNBOOST_PP_IIF(p(6), NDNBOOST_PP_NODE_5, NDNBOOST_PP_NODE_7)
#                            define NDNBOOST_PP_NODE_5(p) NDNBOOST_PP_IIF(p(5), 5, 6)
#                            define NDNBOOST_PP_NODE_7(p) NDNBOOST_PP_IIF(p(7), 7, 8)
#                    define NDNBOOST_PP_NODE_12(p) NDNBOOST_PP_IIF(p(12), NDNBOOST_PP_NODE_10, NDNBOOST_PP_NODE_14)
#                        define NDNBOOST_PP_NODE_10(p) NDNBOOST_PP_IIF(p(10), NDNBOOST_PP_NODE_9, NDNBOOST_PP_NODE_11)
#                            define NDNBOOST_PP_NODE_9(p) NDNBOOST_PP_IIF(p(9), 9, 10)
#                            define NDNBOOST_PP_NODE_11(p) NDNBOOST_PP_IIF(p(11), 11, 12)
#                        define NDNBOOST_PP_NODE_14(p) NDNBOOST_PP_IIF(p(14), NDNBOOST_PP_NODE_13, NDNBOOST_PP_NODE_15)
#                            define NDNBOOST_PP_NODE_13(p) NDNBOOST_PP_IIF(p(13), 13, 14)
#                            define NDNBOOST_PP_NODE_15(p) NDNBOOST_PP_IIF(p(15), 15, 16)
#                define NDNBOOST_PP_NODE_24(p) NDNBOOST_PP_IIF(p(24), NDNBOOST_PP_NODE_20, NDNBOOST_PP_NODE_28)
#                    define NDNBOOST_PP_NODE_20(p) NDNBOOST_PP_IIF(p(20), NDNBOOST_PP_NODE_18, NDNBOOST_PP_NODE_22)
#                        define NDNBOOST_PP_NODE_18(p) NDNBOOST_PP_IIF(p(18), NDNBOOST_PP_NODE_17, NDNBOOST_PP_NODE_19)
#                            define NDNBOOST_PP_NODE_17(p) NDNBOOST_PP_IIF(p(17), 17, 18)
#                            define NDNBOOST_PP_NODE_19(p) NDNBOOST_PP_IIF(p(19), 19, 20)
#                        define NDNBOOST_PP_NODE_22(p) NDNBOOST_PP_IIF(p(22), NDNBOOST_PP_NODE_21, NDNBOOST_PP_NODE_23)
#                            define NDNBOOST_PP_NODE_21(p) NDNBOOST_PP_IIF(p(21), 21, 22)
#                            define NDNBOOST_PP_NODE_23(p) NDNBOOST_PP_IIF(p(23), 23, 24)
#                    define NDNBOOST_PP_NODE_28(p) NDNBOOST_PP_IIF(p(28), NDNBOOST_PP_NODE_26, NDNBOOST_PP_NODE_30)
#                        define NDNBOOST_PP_NODE_26(p) NDNBOOST_PP_IIF(p(26), NDNBOOST_PP_NODE_25, NDNBOOST_PP_NODE_27)
#                            define NDNBOOST_PP_NODE_25(p) NDNBOOST_PP_IIF(p(25), 25, 26)
#                            define NDNBOOST_PP_NODE_27(p) NDNBOOST_PP_IIF(p(27), 27, 28)
#                        define NDNBOOST_PP_NODE_30(p) NDNBOOST_PP_IIF(p(30), NDNBOOST_PP_NODE_29, NDNBOOST_PP_NODE_31)
#                            define NDNBOOST_PP_NODE_29(p) NDNBOOST_PP_IIF(p(29), 29, 30)
#                            define NDNBOOST_PP_NODE_31(p) NDNBOOST_PP_IIF(p(31), 31, 32)
#            define NDNBOOST_PP_NODE_48(p) NDNBOOST_PP_IIF(p(48), NDNBOOST_PP_NODE_40, NDNBOOST_PP_NODE_56)
#                define NDNBOOST_PP_NODE_40(p) NDNBOOST_PP_IIF(p(40), NDNBOOST_PP_NODE_36, NDNBOOST_PP_NODE_44)
#                    define NDNBOOST_PP_NODE_36(p) NDNBOOST_PP_IIF(p(36), NDNBOOST_PP_NODE_34, NDNBOOST_PP_NODE_38)
#                        define NDNBOOST_PP_NODE_34(p) NDNBOOST_PP_IIF(p(34), NDNBOOST_PP_NODE_33, NDNBOOST_PP_NODE_35)
#                            define NDNBOOST_PP_NODE_33(p) NDNBOOST_PP_IIF(p(33), 33, 34)
#                            define NDNBOOST_PP_NODE_35(p) NDNBOOST_PP_IIF(p(35), 35, 36)
#                        define NDNBOOST_PP_NODE_38(p) NDNBOOST_PP_IIF(p(38), NDNBOOST_PP_NODE_37, NDNBOOST_PP_NODE_39)
#                            define NDNBOOST_PP_NODE_37(p) NDNBOOST_PP_IIF(p(37), 37, 38)
#                            define NDNBOOST_PP_NODE_39(p) NDNBOOST_PP_IIF(p(39), 39, 40)
#                    define NDNBOOST_PP_NODE_44(p) NDNBOOST_PP_IIF(p(44), NDNBOOST_PP_NODE_42, NDNBOOST_PP_NODE_46)
#                        define NDNBOOST_PP_NODE_42(p) NDNBOOST_PP_IIF(p(42), NDNBOOST_PP_NODE_41, NDNBOOST_PP_NODE_43)
#                            define NDNBOOST_PP_NODE_41(p) NDNBOOST_PP_IIF(p(41), 41, 42)
#                            define NDNBOOST_PP_NODE_43(p) NDNBOOST_PP_IIF(p(43), 43, 44)
#                        define NDNBOOST_PP_NODE_46(p) NDNBOOST_PP_IIF(p(46), NDNBOOST_PP_NODE_45, NDNBOOST_PP_NODE_47)
#                            define NDNBOOST_PP_NODE_45(p) NDNBOOST_PP_IIF(p(45), 45, 46)
#                            define NDNBOOST_PP_NODE_47(p) NDNBOOST_PP_IIF(p(47), 47, 48)
#                define NDNBOOST_PP_NODE_56(p) NDNBOOST_PP_IIF(p(56), NDNBOOST_PP_NODE_52, NDNBOOST_PP_NODE_60)
#                    define NDNBOOST_PP_NODE_52(p) NDNBOOST_PP_IIF(p(52), NDNBOOST_PP_NODE_50, NDNBOOST_PP_NODE_54)
#                        define NDNBOOST_PP_NODE_50(p) NDNBOOST_PP_IIF(p(50), NDNBOOST_PP_NODE_49, NDNBOOST_PP_NODE_51)
#                            define NDNBOOST_PP_NODE_49(p) NDNBOOST_PP_IIF(p(49), 49, 50)
#                            define NDNBOOST_PP_NODE_51(p) NDNBOOST_PP_IIF(p(51), 51, 52)
#                        define NDNBOOST_PP_NODE_54(p) NDNBOOST_PP_IIF(p(54), NDNBOOST_PP_NODE_53, NDNBOOST_PP_NODE_55)
#                            define NDNBOOST_PP_NODE_53(p) NDNBOOST_PP_IIF(p(53), 53, 54)
#                            define NDNBOOST_PP_NODE_55(p) NDNBOOST_PP_IIF(p(55), 55, 56)
#                    define NDNBOOST_PP_NODE_60(p) NDNBOOST_PP_IIF(p(60), NDNBOOST_PP_NODE_58, NDNBOOST_PP_NODE_62)
#                        define NDNBOOST_PP_NODE_58(p) NDNBOOST_PP_IIF(p(58), NDNBOOST_PP_NODE_57, NDNBOOST_PP_NODE_59)
#                            define NDNBOOST_PP_NODE_57(p) NDNBOOST_PP_IIF(p(57), 57, 58)
#                            define NDNBOOST_PP_NODE_59(p) NDNBOOST_PP_IIF(p(59), 59, 60)
#                        define NDNBOOST_PP_NODE_62(p) NDNBOOST_PP_IIF(p(62), NDNBOOST_PP_NODE_61, NDNBOOST_PP_NODE_63)
#                            define NDNBOOST_PP_NODE_61(p) NDNBOOST_PP_IIF(p(61), 61, 62)
#                            define NDNBOOST_PP_NODE_63(p) NDNBOOST_PP_IIF(p(63), 63, 64)
#        define NDNBOOST_PP_NODE_96(p) NDNBOOST_PP_IIF(p(96), NDNBOOST_PP_NODE_80, NDNBOOST_PP_NODE_112)
#            define NDNBOOST_PP_NODE_80(p) NDNBOOST_PP_IIF(p(80), NDNBOOST_PP_NODE_72, NDNBOOST_PP_NODE_88)
#                define NDNBOOST_PP_NODE_72(p) NDNBOOST_PP_IIF(p(72), NDNBOOST_PP_NODE_68, NDNBOOST_PP_NODE_76)
#                    define NDNBOOST_PP_NODE_68(p) NDNBOOST_PP_IIF(p(68), NDNBOOST_PP_NODE_66, NDNBOOST_PP_NODE_70)
#                        define NDNBOOST_PP_NODE_66(p) NDNBOOST_PP_IIF(p(66), NDNBOOST_PP_NODE_65, NDNBOOST_PP_NODE_67)
#                            define NDNBOOST_PP_NODE_65(p) NDNBOOST_PP_IIF(p(65), 65, 66)
#                            define NDNBOOST_PP_NODE_67(p) NDNBOOST_PP_IIF(p(67), 67, 68)
#                        define NDNBOOST_PP_NODE_70(p) NDNBOOST_PP_IIF(p(70), NDNBOOST_PP_NODE_69, NDNBOOST_PP_NODE_71)
#                            define NDNBOOST_PP_NODE_69(p) NDNBOOST_PP_IIF(p(69), 69, 70)
#                            define NDNBOOST_PP_NODE_71(p) NDNBOOST_PP_IIF(p(71), 71, 72)
#                    define NDNBOOST_PP_NODE_76(p) NDNBOOST_PP_IIF(p(76), NDNBOOST_PP_NODE_74, NDNBOOST_PP_NODE_78)
#                        define NDNBOOST_PP_NODE_74(p) NDNBOOST_PP_IIF(p(74), NDNBOOST_PP_NODE_73, NDNBOOST_PP_NODE_75)
#                            define NDNBOOST_PP_NODE_73(p) NDNBOOST_PP_IIF(p(73), 73, 74)
#                            define NDNBOOST_PP_NODE_75(p) NDNBOOST_PP_IIF(p(75), 75, 76)
#                        define NDNBOOST_PP_NODE_78(p) NDNBOOST_PP_IIF(p(78), NDNBOOST_PP_NODE_77, NDNBOOST_PP_NODE_79)
#                            define NDNBOOST_PP_NODE_77(p) NDNBOOST_PP_IIF(p(77), 77, 78)
#                            define NDNBOOST_PP_NODE_79(p) NDNBOOST_PP_IIF(p(79), 79, 80)
#                define NDNBOOST_PP_NODE_88(p) NDNBOOST_PP_IIF(p(88), NDNBOOST_PP_NODE_84, NDNBOOST_PP_NODE_92)
#                    define NDNBOOST_PP_NODE_84(p) NDNBOOST_PP_IIF(p(84), NDNBOOST_PP_NODE_82, NDNBOOST_PP_NODE_86)
#                        define NDNBOOST_PP_NODE_82(p) NDNBOOST_PP_IIF(p(82), NDNBOOST_PP_NODE_81, NDNBOOST_PP_NODE_83)
#                            define NDNBOOST_PP_NODE_81(p) NDNBOOST_PP_IIF(p(81), 81, 82)
#                            define NDNBOOST_PP_NODE_83(p) NDNBOOST_PP_IIF(p(83), 83, 84)
#                        define NDNBOOST_PP_NODE_86(p) NDNBOOST_PP_IIF(p(86), NDNBOOST_PP_NODE_85, NDNBOOST_PP_NODE_87)
#                            define NDNBOOST_PP_NODE_85(p) NDNBOOST_PP_IIF(p(85), 85, 86)
#                            define NDNBOOST_PP_NODE_87(p) NDNBOOST_PP_IIF(p(87), 87, 88)
#                    define NDNBOOST_PP_NODE_92(p) NDNBOOST_PP_IIF(p(92), NDNBOOST_PP_NODE_90, NDNBOOST_PP_NODE_94)
#                        define NDNBOOST_PP_NODE_90(p) NDNBOOST_PP_IIF(p(90), NDNBOOST_PP_NODE_89, NDNBOOST_PP_NODE_91)
#                            define NDNBOOST_PP_NODE_89(p) NDNBOOST_PP_IIF(p(89), 89, 90)
#                            define NDNBOOST_PP_NODE_91(p) NDNBOOST_PP_IIF(p(91), 91, 92)
#                        define NDNBOOST_PP_NODE_94(p) NDNBOOST_PP_IIF(p(94), NDNBOOST_PP_NODE_93, NDNBOOST_PP_NODE_95)
#                            define NDNBOOST_PP_NODE_93(p) NDNBOOST_PP_IIF(p(93), 93, 94)
#                            define NDNBOOST_PP_NODE_95(p) NDNBOOST_PP_IIF(p(95), 95, 96)
#            define NDNBOOST_PP_NODE_112(p) NDNBOOST_PP_IIF(p(112), NDNBOOST_PP_NODE_104, NDNBOOST_PP_NODE_120)
#                define NDNBOOST_PP_NODE_104(p) NDNBOOST_PP_IIF(p(104), NDNBOOST_PP_NODE_100, NDNBOOST_PP_NODE_108)
#                    define NDNBOOST_PP_NODE_100(p) NDNBOOST_PP_IIF(p(100), NDNBOOST_PP_NODE_98, NDNBOOST_PP_NODE_102)
#                        define NDNBOOST_PP_NODE_98(p) NDNBOOST_PP_IIF(p(98), NDNBOOST_PP_NODE_97, NDNBOOST_PP_NODE_99)
#                            define NDNBOOST_PP_NODE_97(p) NDNBOOST_PP_IIF(p(97), 97, 98)
#                            define NDNBOOST_PP_NODE_99(p) NDNBOOST_PP_IIF(p(99), 99, 100)
#                        define NDNBOOST_PP_NODE_102(p) NDNBOOST_PP_IIF(p(102), NDNBOOST_PP_NODE_101, NDNBOOST_PP_NODE_103)
#                            define NDNBOOST_PP_NODE_101(p) NDNBOOST_PP_IIF(p(101), 101, 102)
#                            define NDNBOOST_PP_NODE_103(p) NDNBOOST_PP_IIF(p(103), 103, 104)
#                    define NDNBOOST_PP_NODE_108(p) NDNBOOST_PP_IIF(p(108), NDNBOOST_PP_NODE_106, NDNBOOST_PP_NODE_110)
#                        define NDNBOOST_PP_NODE_106(p) NDNBOOST_PP_IIF(p(106), NDNBOOST_PP_NODE_105, NDNBOOST_PP_NODE_107)
#                            define NDNBOOST_PP_NODE_105(p) NDNBOOST_PP_IIF(p(105), 105, 106)
#                            define NDNBOOST_PP_NODE_107(p) NDNBOOST_PP_IIF(p(107), 107, 108)
#                        define NDNBOOST_PP_NODE_110(p) NDNBOOST_PP_IIF(p(110), NDNBOOST_PP_NODE_109, NDNBOOST_PP_NODE_111)
#                            define NDNBOOST_PP_NODE_109(p) NDNBOOST_PP_IIF(p(109), 109, 110)
#                            define NDNBOOST_PP_NODE_111(p) NDNBOOST_PP_IIF(p(111), 111, 112)
#                define NDNBOOST_PP_NODE_120(p) NDNBOOST_PP_IIF(p(120), NDNBOOST_PP_NODE_116, NDNBOOST_PP_NODE_124)
#                    define NDNBOOST_PP_NODE_116(p) NDNBOOST_PP_IIF(p(116), NDNBOOST_PP_NODE_114, NDNBOOST_PP_NODE_118)
#                        define NDNBOOST_PP_NODE_114(p) NDNBOOST_PP_IIF(p(114), NDNBOOST_PP_NODE_113, NDNBOOST_PP_NODE_115)
#                            define NDNBOOST_PP_NODE_113(p) NDNBOOST_PP_IIF(p(113), 113, 114)
#                            define NDNBOOST_PP_NODE_115(p) NDNBOOST_PP_IIF(p(115), 115, 116)
#                        define NDNBOOST_PP_NODE_118(p) NDNBOOST_PP_IIF(p(118), NDNBOOST_PP_NODE_117, NDNBOOST_PP_NODE_119)
#                            define NDNBOOST_PP_NODE_117(p) NDNBOOST_PP_IIF(p(117), 117, 118)
#                            define NDNBOOST_PP_NODE_119(p) NDNBOOST_PP_IIF(p(119), 119, 120)
#                    define NDNBOOST_PP_NODE_124(p) NDNBOOST_PP_IIF(p(124), NDNBOOST_PP_NODE_122, NDNBOOST_PP_NODE_126)
#                        define NDNBOOST_PP_NODE_122(p) NDNBOOST_PP_IIF(p(122), NDNBOOST_PP_NODE_121, NDNBOOST_PP_NODE_123)
#                            define NDNBOOST_PP_NODE_121(p) NDNBOOST_PP_IIF(p(121), 121, 122)
#                            define NDNBOOST_PP_NODE_123(p) NDNBOOST_PP_IIF(p(123), 123, 124)
#                        define NDNBOOST_PP_NODE_126(p) NDNBOOST_PP_IIF(p(126), NDNBOOST_PP_NODE_125, NDNBOOST_PP_NODE_127)
#                            define NDNBOOST_PP_NODE_125(p) NDNBOOST_PP_IIF(p(125), 125, 126)
#                            define NDNBOOST_PP_NODE_127(p) NDNBOOST_PP_IIF(p(127), 127, 128)
#    define NDNBOOST_PP_NODE_192(p) NDNBOOST_PP_IIF(p(192), NDNBOOST_PP_NODE_160, NDNBOOST_PP_NODE_224)
#        define NDNBOOST_PP_NODE_160(p) NDNBOOST_PP_IIF(p(160), NDNBOOST_PP_NODE_144, NDNBOOST_PP_NODE_176)
#            define NDNBOOST_PP_NODE_144(p) NDNBOOST_PP_IIF(p(144), NDNBOOST_PP_NODE_136, NDNBOOST_PP_NODE_152)
#                define NDNBOOST_PP_NODE_136(p) NDNBOOST_PP_IIF(p(136), NDNBOOST_PP_NODE_132, NDNBOOST_PP_NODE_140)
#                    define NDNBOOST_PP_NODE_132(p) NDNBOOST_PP_IIF(p(132), NDNBOOST_PP_NODE_130, NDNBOOST_PP_NODE_134)
#                        define NDNBOOST_PP_NODE_130(p) NDNBOOST_PP_IIF(p(130), NDNBOOST_PP_NODE_129, NDNBOOST_PP_NODE_131)
#                            define NDNBOOST_PP_NODE_129(p) NDNBOOST_PP_IIF(p(129), 129, 130)
#                            define NDNBOOST_PP_NODE_131(p) NDNBOOST_PP_IIF(p(131), 131, 132)
#                        define NDNBOOST_PP_NODE_134(p) NDNBOOST_PP_IIF(p(134), NDNBOOST_PP_NODE_133, NDNBOOST_PP_NODE_135)
#                            define NDNBOOST_PP_NODE_133(p) NDNBOOST_PP_IIF(p(133), 133, 134)
#                            define NDNBOOST_PP_NODE_135(p) NDNBOOST_PP_IIF(p(135), 135, 136)
#                    define NDNBOOST_PP_NODE_140(p) NDNBOOST_PP_IIF(p(140), NDNBOOST_PP_NODE_138, NDNBOOST_PP_NODE_142)
#                        define NDNBOOST_PP_NODE_138(p) NDNBOOST_PP_IIF(p(138), NDNBOOST_PP_NODE_137, NDNBOOST_PP_NODE_139)
#                            define NDNBOOST_PP_NODE_137(p) NDNBOOST_PP_IIF(p(137), 137, 138)
#                            define NDNBOOST_PP_NODE_139(p) NDNBOOST_PP_IIF(p(139), 139, 140)
#                        define NDNBOOST_PP_NODE_142(p) NDNBOOST_PP_IIF(p(142), NDNBOOST_PP_NODE_141, NDNBOOST_PP_NODE_143)
#                            define NDNBOOST_PP_NODE_141(p) NDNBOOST_PP_IIF(p(141), 141, 142)
#                            define NDNBOOST_PP_NODE_143(p) NDNBOOST_PP_IIF(p(143), 143, 144)
#                define NDNBOOST_PP_NODE_152(p) NDNBOOST_PP_IIF(p(152), NDNBOOST_PP_NODE_148, NDNBOOST_PP_NODE_156)
#                    define NDNBOOST_PP_NODE_148(p) NDNBOOST_PP_IIF(p(148), NDNBOOST_PP_NODE_146, NDNBOOST_PP_NODE_150)
#                        define NDNBOOST_PP_NODE_146(p) NDNBOOST_PP_IIF(p(146), NDNBOOST_PP_NODE_145, NDNBOOST_PP_NODE_147)
#                            define NDNBOOST_PP_NODE_145(p) NDNBOOST_PP_IIF(p(145), 145, 146)
#                            define NDNBOOST_PP_NODE_147(p) NDNBOOST_PP_IIF(p(147), 147, 148)
#                        define NDNBOOST_PP_NODE_150(p) NDNBOOST_PP_IIF(p(150), NDNBOOST_PP_NODE_149, NDNBOOST_PP_NODE_151)
#                            define NDNBOOST_PP_NODE_149(p) NDNBOOST_PP_IIF(p(149), 149, 150)
#                            define NDNBOOST_PP_NODE_151(p) NDNBOOST_PP_IIF(p(151), 151, 152)
#                    define NDNBOOST_PP_NODE_156(p) NDNBOOST_PP_IIF(p(156), NDNBOOST_PP_NODE_154, NDNBOOST_PP_NODE_158)
#                        define NDNBOOST_PP_NODE_154(p) NDNBOOST_PP_IIF(p(154), NDNBOOST_PP_NODE_153, NDNBOOST_PP_NODE_155)
#                            define NDNBOOST_PP_NODE_153(p) NDNBOOST_PP_IIF(p(153), 153, 154)
#                            define NDNBOOST_PP_NODE_155(p) NDNBOOST_PP_IIF(p(155), 155, 156)
#                        define NDNBOOST_PP_NODE_158(p) NDNBOOST_PP_IIF(p(158), NDNBOOST_PP_NODE_157, NDNBOOST_PP_NODE_159)
#                            define NDNBOOST_PP_NODE_157(p) NDNBOOST_PP_IIF(p(157), 157, 158)
#                            define NDNBOOST_PP_NODE_159(p) NDNBOOST_PP_IIF(p(159), 159, 160)
#            define NDNBOOST_PP_NODE_176(p) NDNBOOST_PP_IIF(p(176), NDNBOOST_PP_NODE_168, NDNBOOST_PP_NODE_184)
#                define NDNBOOST_PP_NODE_168(p) NDNBOOST_PP_IIF(p(168), NDNBOOST_PP_NODE_164, NDNBOOST_PP_NODE_172)
#                    define NDNBOOST_PP_NODE_164(p) NDNBOOST_PP_IIF(p(164), NDNBOOST_PP_NODE_162, NDNBOOST_PP_NODE_166)
#                        define NDNBOOST_PP_NODE_162(p) NDNBOOST_PP_IIF(p(162), NDNBOOST_PP_NODE_161, NDNBOOST_PP_NODE_163)
#                            define NDNBOOST_PP_NODE_161(p) NDNBOOST_PP_IIF(p(161), 161, 162)
#                            define NDNBOOST_PP_NODE_163(p) NDNBOOST_PP_IIF(p(163), 163, 164)
#                        define NDNBOOST_PP_NODE_166(p) NDNBOOST_PP_IIF(p(166), NDNBOOST_PP_NODE_165, NDNBOOST_PP_NODE_167)
#                            define NDNBOOST_PP_NODE_165(p) NDNBOOST_PP_IIF(p(165), 165, 166)
#                            define NDNBOOST_PP_NODE_167(p) NDNBOOST_PP_IIF(p(167), 167, 168)
#                    define NDNBOOST_PP_NODE_172(p) NDNBOOST_PP_IIF(p(172), NDNBOOST_PP_NODE_170, NDNBOOST_PP_NODE_174)
#                        define NDNBOOST_PP_NODE_170(p) NDNBOOST_PP_IIF(p(170), NDNBOOST_PP_NODE_169, NDNBOOST_PP_NODE_171)
#                            define NDNBOOST_PP_NODE_169(p) NDNBOOST_PP_IIF(p(169), 169, 170)
#                            define NDNBOOST_PP_NODE_171(p) NDNBOOST_PP_IIF(p(171), 171, 172)
#                        define NDNBOOST_PP_NODE_174(p) NDNBOOST_PP_IIF(p(174), NDNBOOST_PP_NODE_173, NDNBOOST_PP_NODE_175)
#                            define NDNBOOST_PP_NODE_173(p) NDNBOOST_PP_IIF(p(173), 173, 174)
#                            define NDNBOOST_PP_NODE_175(p) NDNBOOST_PP_IIF(p(175), 175, 176)
#                define NDNBOOST_PP_NODE_184(p) NDNBOOST_PP_IIF(p(184), NDNBOOST_PP_NODE_180, NDNBOOST_PP_NODE_188)
#                    define NDNBOOST_PP_NODE_180(p) NDNBOOST_PP_IIF(p(180), NDNBOOST_PP_NODE_178, NDNBOOST_PP_NODE_182)
#                        define NDNBOOST_PP_NODE_178(p) NDNBOOST_PP_IIF(p(178), NDNBOOST_PP_NODE_177, NDNBOOST_PP_NODE_179)
#                            define NDNBOOST_PP_NODE_177(p) NDNBOOST_PP_IIF(p(177), 177, 178)
#                            define NDNBOOST_PP_NODE_179(p) NDNBOOST_PP_IIF(p(179), 179, 180)
#                        define NDNBOOST_PP_NODE_182(p) NDNBOOST_PP_IIF(p(182), NDNBOOST_PP_NODE_181, NDNBOOST_PP_NODE_183)
#                            define NDNBOOST_PP_NODE_181(p) NDNBOOST_PP_IIF(p(181), 181, 182)
#                            define NDNBOOST_PP_NODE_183(p) NDNBOOST_PP_IIF(p(183), 183, 184)
#                    define NDNBOOST_PP_NODE_188(p) NDNBOOST_PP_IIF(p(188), NDNBOOST_PP_NODE_186, NDNBOOST_PP_NODE_190)
#                        define NDNBOOST_PP_NODE_186(p) NDNBOOST_PP_IIF(p(186), NDNBOOST_PP_NODE_185, NDNBOOST_PP_NODE_187)
#                            define NDNBOOST_PP_NODE_185(p) NDNBOOST_PP_IIF(p(185), 185, 186)
#                            define NDNBOOST_PP_NODE_187(p) NDNBOOST_PP_IIF(p(187), 187, 188)
#                        define NDNBOOST_PP_NODE_190(p) NDNBOOST_PP_IIF(p(190), NDNBOOST_PP_NODE_189, NDNBOOST_PP_NODE_191)
#                            define NDNBOOST_PP_NODE_189(p) NDNBOOST_PP_IIF(p(189), 189, 190)
#                            define NDNBOOST_PP_NODE_191(p) NDNBOOST_PP_IIF(p(191), 191, 192)
#        define NDNBOOST_PP_NODE_224(p) NDNBOOST_PP_IIF(p(224), NDNBOOST_PP_NODE_208, NDNBOOST_PP_NODE_240)
#            define NDNBOOST_PP_NODE_208(p) NDNBOOST_PP_IIF(p(208), NDNBOOST_PP_NODE_200, NDNBOOST_PP_NODE_216)
#                define NDNBOOST_PP_NODE_200(p) NDNBOOST_PP_IIF(p(200), NDNBOOST_PP_NODE_196, NDNBOOST_PP_NODE_204)
#                    define NDNBOOST_PP_NODE_196(p) NDNBOOST_PP_IIF(p(196), NDNBOOST_PP_NODE_194, NDNBOOST_PP_NODE_198)
#                        define NDNBOOST_PP_NODE_194(p) NDNBOOST_PP_IIF(p(194), NDNBOOST_PP_NODE_193, NDNBOOST_PP_NODE_195)
#                            define NDNBOOST_PP_NODE_193(p) NDNBOOST_PP_IIF(p(193), 193, 194)
#                            define NDNBOOST_PP_NODE_195(p) NDNBOOST_PP_IIF(p(195), 195, 196)
#                        define NDNBOOST_PP_NODE_198(p) NDNBOOST_PP_IIF(p(198), NDNBOOST_PP_NODE_197, NDNBOOST_PP_NODE_199)
#                            define NDNBOOST_PP_NODE_197(p) NDNBOOST_PP_IIF(p(197), 197, 198)
#                            define NDNBOOST_PP_NODE_199(p) NDNBOOST_PP_IIF(p(199), 199, 200)
#                    define NDNBOOST_PP_NODE_204(p) NDNBOOST_PP_IIF(p(204), NDNBOOST_PP_NODE_202, NDNBOOST_PP_NODE_206)
#                        define NDNBOOST_PP_NODE_202(p) NDNBOOST_PP_IIF(p(202), NDNBOOST_PP_NODE_201, NDNBOOST_PP_NODE_203)
#                            define NDNBOOST_PP_NODE_201(p) NDNBOOST_PP_IIF(p(201), 201, 202)
#                            define NDNBOOST_PP_NODE_203(p) NDNBOOST_PP_IIF(p(203), 203, 204)
#                        define NDNBOOST_PP_NODE_206(p) NDNBOOST_PP_IIF(p(206), NDNBOOST_PP_NODE_205, NDNBOOST_PP_NODE_207)
#                            define NDNBOOST_PP_NODE_205(p) NDNBOOST_PP_IIF(p(205), 205, 206)
#                            define NDNBOOST_PP_NODE_207(p) NDNBOOST_PP_IIF(p(207), 207, 208)
#                define NDNBOOST_PP_NODE_216(p) NDNBOOST_PP_IIF(p(216), NDNBOOST_PP_NODE_212, NDNBOOST_PP_NODE_220)
#                    define NDNBOOST_PP_NODE_212(p) NDNBOOST_PP_IIF(p(212), NDNBOOST_PP_NODE_210, NDNBOOST_PP_NODE_214)
#                        define NDNBOOST_PP_NODE_210(p) NDNBOOST_PP_IIF(p(210), NDNBOOST_PP_NODE_209, NDNBOOST_PP_NODE_211)
#                            define NDNBOOST_PP_NODE_209(p) NDNBOOST_PP_IIF(p(209), 209, 210)
#                            define NDNBOOST_PP_NODE_211(p) NDNBOOST_PP_IIF(p(211), 211, 212)
#                        define NDNBOOST_PP_NODE_214(p) NDNBOOST_PP_IIF(p(214), NDNBOOST_PP_NODE_213, NDNBOOST_PP_NODE_215)
#                            define NDNBOOST_PP_NODE_213(p) NDNBOOST_PP_IIF(p(213), 213, 214)
#                            define NDNBOOST_PP_NODE_215(p) NDNBOOST_PP_IIF(p(215), 215, 216)
#                    define NDNBOOST_PP_NODE_220(p) NDNBOOST_PP_IIF(p(220), NDNBOOST_PP_NODE_218, NDNBOOST_PP_NODE_222)
#                        define NDNBOOST_PP_NODE_218(p) NDNBOOST_PP_IIF(p(218), NDNBOOST_PP_NODE_217, NDNBOOST_PP_NODE_219)
#                            define NDNBOOST_PP_NODE_217(p) NDNBOOST_PP_IIF(p(217), 217, 218)
#                            define NDNBOOST_PP_NODE_219(p) NDNBOOST_PP_IIF(p(219), 219, 220)
#                        define NDNBOOST_PP_NODE_222(p) NDNBOOST_PP_IIF(p(222), NDNBOOST_PP_NODE_221, NDNBOOST_PP_NODE_223)
#                            define NDNBOOST_PP_NODE_221(p) NDNBOOST_PP_IIF(p(221), 221, 222)
#                            define NDNBOOST_PP_NODE_223(p) NDNBOOST_PP_IIF(p(223), 223, 224)
#            define NDNBOOST_PP_NODE_240(p) NDNBOOST_PP_IIF(p(240), NDNBOOST_PP_NODE_232, NDNBOOST_PP_NODE_248)
#                define NDNBOOST_PP_NODE_232(p) NDNBOOST_PP_IIF(p(232), NDNBOOST_PP_NODE_228, NDNBOOST_PP_NODE_236)
#                    define NDNBOOST_PP_NODE_228(p) NDNBOOST_PP_IIF(p(228), NDNBOOST_PP_NODE_226, NDNBOOST_PP_NODE_230)
#                        define NDNBOOST_PP_NODE_226(p) NDNBOOST_PP_IIF(p(226), NDNBOOST_PP_NODE_225, NDNBOOST_PP_NODE_227)
#                            define NDNBOOST_PP_NODE_225(p) NDNBOOST_PP_IIF(p(225), 225, 226)
#                            define NDNBOOST_PP_NODE_227(p) NDNBOOST_PP_IIF(p(227), 227, 228)
#                        define NDNBOOST_PP_NODE_230(p) NDNBOOST_PP_IIF(p(230), NDNBOOST_PP_NODE_229, NDNBOOST_PP_NODE_231)
#                            define NDNBOOST_PP_NODE_229(p) NDNBOOST_PP_IIF(p(229), 229, 230)
#                            define NDNBOOST_PP_NODE_231(p) NDNBOOST_PP_IIF(p(231), 231, 232)
#                    define NDNBOOST_PP_NODE_236(p) NDNBOOST_PP_IIF(p(236), NDNBOOST_PP_NODE_234, NDNBOOST_PP_NODE_238)
#                        define NDNBOOST_PP_NODE_234(p) NDNBOOST_PP_IIF(p(234), NDNBOOST_PP_NODE_233, NDNBOOST_PP_NODE_235)
#                            define NDNBOOST_PP_NODE_233(p) NDNBOOST_PP_IIF(p(233), 233, 234)
#                            define NDNBOOST_PP_NODE_235(p) NDNBOOST_PP_IIF(p(235), 235, 236)
#                        define NDNBOOST_PP_NODE_238(p) NDNBOOST_PP_IIF(p(238), NDNBOOST_PP_NODE_237, NDNBOOST_PP_NODE_239)
#                            define NDNBOOST_PP_NODE_237(p) NDNBOOST_PP_IIF(p(237), 237, 238)
#                            define NDNBOOST_PP_NODE_239(p) NDNBOOST_PP_IIF(p(239), 239, 240)
#                define NDNBOOST_PP_NODE_248(p) NDNBOOST_PP_IIF(p(248), NDNBOOST_PP_NODE_244, NDNBOOST_PP_NODE_252)
#                    define NDNBOOST_PP_NODE_244(p) NDNBOOST_PP_IIF(p(244), NDNBOOST_PP_NODE_242, NDNBOOST_PP_NODE_246)
#                        define NDNBOOST_PP_NODE_242(p) NDNBOOST_PP_IIF(p(242), NDNBOOST_PP_NODE_241, NDNBOOST_PP_NODE_243)
#                            define NDNBOOST_PP_NODE_241(p) NDNBOOST_PP_IIF(p(241), 241, 242)
#                            define NDNBOOST_PP_NODE_243(p) NDNBOOST_PP_IIF(p(243), 243, 244)
#                        define NDNBOOST_PP_NODE_246(p) NDNBOOST_PP_IIF(p(246), NDNBOOST_PP_NODE_245, NDNBOOST_PP_NODE_247)
#                            define NDNBOOST_PP_NODE_245(p) NDNBOOST_PP_IIF(p(245), 245, 246)
#                            define NDNBOOST_PP_NODE_247(p) NDNBOOST_PP_IIF(p(247), 247, 248)
#                    define NDNBOOST_PP_NODE_252(p) NDNBOOST_PP_IIF(p(252), NDNBOOST_PP_NODE_250, NDNBOOST_PP_NODE_254)
#                        define NDNBOOST_PP_NODE_250(p) NDNBOOST_PP_IIF(p(250), NDNBOOST_PP_NODE_249, NDNBOOST_PP_NODE_251)
#                            define NDNBOOST_PP_NODE_249(p) NDNBOOST_PP_IIF(p(249), 249, 250)
#                            define NDNBOOST_PP_NODE_251(p) NDNBOOST_PP_IIF(p(251), 251, 252)
#                        define NDNBOOST_PP_NODE_254(p) NDNBOOST_PP_IIF(p(254), NDNBOOST_PP_NODE_253, NDNBOOST_PP_NODE_255)
#                            define NDNBOOST_PP_NODE_253(p) NDNBOOST_PP_IIF(p(253), 253, 254)
#                            define NDNBOOST_PP_NODE_255(p) NDNBOOST_PP_IIF(p(255), 255, 256)
#
# endif
# endif
