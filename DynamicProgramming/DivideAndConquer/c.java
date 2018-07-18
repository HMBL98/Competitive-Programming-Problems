// Arup Guha
// Originally written 4/16/2016 in contest. Edited on 4/20/2016 to be much cleaner.
// Solution to 2016 NAIPC Problem C: Greetings!

import java.util.*;

public class c {

	public static int n;
	public static int k;
	public static card[] cards;

	public static void main(String[] args) {

		// Get input.
		Scanner stdin = new Scanner(System.in);
		n = stdin.nextInt();
		k = stdin.nextInt();
		cards = new card[n];
		for (int i=0; i<n; i++) {
			int w = stdin.nextInt();
			int h = stdin.nextInt();
			int q = stdin.nextInt();
			cards[i] = new card(w,h,q);
		}

		// Pre-compute envelope dimensions for each subset.
		int[][] dim = new int[1<<n][2];
		long[] costs = new long[1<<n];
		for (int i=0; i<dim.length; i++) {

			// Figure out subset with mask i, getting max dimensions for it.
			int maxW = 0, maxH = 0;
			for (int j=0; j<n; j++) {
				if ((i & (1<<j)) != 0) {
					maxW = Math.max(maxW, cards[j].w);
					maxH = Math.max(maxH, cards[j].h);
				}
			}

			// Set the max dimensions, then calculate the cost of these cards for this one envelope.
			dim[i][0] = maxW;
			dim[i][1] = maxH;
			costs[i] = 0;
			for (int j=0; j<n; j++)
				if ((i & (1<<j)) != 0)
					costs[i] = costs[i] + ((long)(maxH*maxW-cards[j].w*cards[j].h))*cards[j].q;
		}

		// Costs were precomuted to be the costs of each subset with 1 envelope.
		long[][] dp = new long[k+1][1<<n];
		for (int i=0; i<(1<<n); i++)
			dp[1][i] = costs[i];

		// Iterate through 2...k different envelopes.
		for (int i=2; i<=k; i++) {

			// Go through covering each possible subset of cards with i envelopes.
			for (int j=0; j<(1<<n); j++) {

				dp[i][j] = dp[i-1][j];

				// Here is the trick to go through subsets of mask j efficiently: (prev-1)&j
				for (int prev=j; prev>0; prev = (prev-1)&j )
					dp[i][j] = Math.min(dp[i][j], dp[i-1][prev]+dp[1][j-prev]);
			}
		}

		// Ta da!
		System.out.println(dp[k][(1<<n)-1]);
	}
}

class card {

	public int w;
	public int h;
	public int q;

	public card(int myW, int myH, int myQ) {
		w = myW;
		h = myH;
		q = myQ;
	}
}
