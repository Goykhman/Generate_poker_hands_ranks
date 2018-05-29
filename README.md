 Generate rankings of all possible distinct 5-card poker hands.

 There are 7462 distinct hands (when not distinguished by an equivalent
 in strength rearrangement of suits):

 #      Name of hand        Number of hands      range of indexes
 1.     Straight Flush      -- 10   --              [0,10)
 2.     Four of a Kind      -- 156  --              [10,166)
 3.     Full House          -- 156  --              [166,322)
 4.     Flush               -- 1277 --              [322,1599)
 5.     Straight            -- 10   --              [1599,1609)
 6.     Three of a Kind     -- 858  --              [1609,2467)
 7.     Two Pair            -- 858  --              [2467,3325)
 8.     Pair                -- 2860 --              [3325,6185)
 9.     High Card           -- 1277 --              [6185,7462)

 The cards are enlisted by their ranks, say, "AKQJT", or "75432". The 
 suits are important only if they are all the same. The cards are also
 sorted in the decreasing order of the rank.

 To use these rankings, first determine if the hand is a flush or not.
 This is because straight flush hands formally are written in the same
 way as non-flush straights, say, "AKQJT" can stand for both the straight
 and the straight flush. The difference is in their ranks. The same
 is for the flush and the high card, for instance, "75432" can both stand
 for the flush, and the high card. Again, these two enter the list twice,
 at different positions, corresponding to differents ranks.

 Therefore first see whether the hand is a flush, and if yes, search it
 among the straight flushes or the flushes.

 Otherwise search it among all other possibilities, where every possible
 representation is unique.
