/* 
 * File:   0019.cpp
 * Author: Pin
 *
 * Created on March 22, 2015, 8:51 AM
 */

#include <iostream>
#include <math.h>

using namespace std;

struct ingredient {
	int s;
	int b;
};

int abs(int i) {
	if (i<0) {
		return -i;
	} else {
		return i;
	}
}

/*
 * 
 */
int main() {
	int n;
	cin >> n;
	ingredient in[n];
	for (int i = 0;i<n;i++) {
		cin >> in[i].s;
		cin >> in[i].b;
	}
	
	int currmin = 1000000001;
	for (int i = 0;i<n;i++) {
		int result = abs(in[i].s - in[i].b);
		if (result < currmin) {
			currmin = result;
		}
	}
	if (n >= 2) {
		for (int i = 0;i<n;i++) {
			for (int i2 = i+1;i2<n;i2++) {
				int result = abs((in[i].s*in[i2].s) - (in[i].b+in[i2].b));
				if (result < currmin) {
					currmin = result;
				}
			}
		}
	}
	if (n >= 3) {
		for (int i = 0;i<n;i++) {
			for (int i2 = i+1;i2<n;i2++) {
				for (int i3 = i2+1;i3<n;i3++) {
					int result = abs((in[i].s*in[i2].s*in[i3].s) - (in[i].b+in[i2].b+in[i3].b));
					if (result < currmin) {
						currmin = result;
					}
				}
			}
		}
	}
	if (n >= 4) {
		for (int i = 0;i<n;i++) {
			for (int i2 = i+1;i2<n;i2++) {
				for (int i3 = i2+1;i3<n;i3++) {
					for (int i4 = i3+1;i4<n;i4++) {
						int result = abs((in[i].s*in[i2].s*in[i3].s*in[i4].s) - (in[i].b+in[i2].b+in[i3].b+in[i4].b));
						if (result < currmin) {
							currmin = result;
						}
					}
				}
			}
		}
	}
	if (n >= 5) {
		for (int i = 0;i<n;i++) {
			for (int i2 = i+1;i2<n;i2++) {
				for (int i3 = i2+1;i3<n;i3++) {
					for (int i4 = i3+1;i4<n;i4++) {
						for (int i5 = i4+1;i5<n;i5++) {
							int result = abs((in[i].s*in[i2].s*in[i3].s*in[i4].s*in[i5].s) - (in[i].b+in[i2].b+in[i3].b+in[i4].b+in[i5].b));
							if (result < currmin) {
								currmin = result;
							}
						}
					}
				}
			}
		}
	}
	if (n >= 6) {
		for (int i = 0;i<n;i++) {
			for (int i2 = i+1;i2<n;i2++) {
				for (int i3 = i2+1;i3<n;i3++) {
					for (int i4 = i3+1;i4<n;i4++) {
						for (int i5 = i4+1;i5<n;i5++) {
							for (int i6 = i5+1;i6<n;i6++) {
								int result = abs((in[i].s*in[i2].s*in[i3].s*in[i4].s*in[i5].s*in[i6].s) - (in[i].b+in[i2].b+in[i3].b+in[i4].b+in[i5].b+in[i6].b));
								if (result < currmin) {
									currmin = result;
								}
							}
						}
					}
				}
			}
		}
	}
	if (n >= 7) {
		for (int i = 0;i<n;i++) {
			for (int i2 = i+1;i2<n;i2++) {
				for (int i3 = i2+1;i3<n;i3++) {
					for (int i4 = i3+1;i4<n;i4++) {
						for (int i5 = i4+1;i5<n;i5++) {
							for (int i6 = i5+1;i6<n;i6++) {
								for (int i7 = i6+1;i7<n;i7++) {
									int result = abs((in[i].s*in[i2].s*in[i3].s*in[i4].s*in[i5].s*in[i6].s*in[i7].s) - (in[i].b+in[i2].b+in[i3].b+in[i4].b+in[i5].b+in[i6].b+in[i7].b));
									if (result < currmin) {
										currmin = result;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (n >= 8) {
		for (int i = 0;i<n;i++) {
			for (int i2 = i+1;i2<n;i2++) {
				for (int i3 = i2+1;i3<n;i3++) {
					for (int i4 = i3+1;i4<n;i4++) {
						for (int i5 = i4+1;i5<n;i5++) {
							for (int i6 = i5+1;i6<n;i6++) {
								for (int i7 = i6+1;i7<n;i7++) {
									for (int i8 = i7+1;i8<n;i8++) {
										int result = abs((in[i].s*in[i2].s*in[i3].s*in[i4].s*in[i5].s*in[i6].s*in[i7].s*in[i8].s) - (in[i].b+in[i2].b+in[i3].b+in[i4].b+in[i5].b+in[i6].b+in[i7].b+in[i8].b));
										if (result < currmin) {
											currmin = result;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (n >= 9) {
		for (int i = 0;i<n;i++) {
			for (int i2 = i+1;i2<n;i2++) {
				for (int i3 = i2+1;i3<n;i3++) {
					for (int i4 = i3+1;i4<n;i4++) {
						for (int i5 = i4+1;i5<n;i5++) {
							for (int i6 = i5+1;i6<n;i6++) {
								for (int i7 = i6+1;i7<n;i7++) {
									for (int i8 = i7+1;i8<n;i8++) {
										for (int i9 = i8+1;i9<n;i9++) {
											int result = abs((in[i].s*in[i2].s*in[i3].s*in[i4].s*in[i5].s*in[i6].s*in[i7].s*in[i8].s*in[i9].s) - (in[i].b+in[i2].b+in[i3].b+in[i4].b+in[i5].b+in[i6].b+in[i7].b+in[i8].b+in[i9].b));
											if (result < currmin) {
												currmin = result;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (n >= 10) {
		for (int i = 0;i<n;i++) {
			for (int i2 = i+1;i2<n;i2++) {
				for (int i3 = i2+1;i3<n;i3++) {
					for (int i4 = i3+1;i4<n;i4++) {
						for (int i5 = i4+1;i5<n;i5++) {
							for (int i6 = i5+1;i6<n;i6++) {
								for (int i7 = i6+1;i7<n;i7++) {
									for (int i8 = i7+1;i8<n;i8++) {
										for (int i9 = i8+1;i9<n;i9++) {
											for (int i10 = i9+1;i10<n;i10++) {
												int result = abs((in[i].s*in[i2].s*in[i3].s*in[i4].s*in[i5].s*in[i6].s*in[i7].s*in[i8].s*in[i9].s*in[i10].s) - (in[i].b+in[i2].b+in[i3].b+in[i4].b+in[i5].b+in[i6].b+in[i7].b+in[i8].b+in[i9].b+in[i10].b));
												if (result < currmin) {
													currmin = result;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << currmin;
	return 0;
}

