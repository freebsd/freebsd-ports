#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int group_member(gid_t gid) {
  gid_t *grouplist = NULL;
  int res,i;

  res = getgroups(0,NULL);
  if (res >= 0) {
    grouplist = calloc(sizeof(gid_t),res);
    res = getgroups(res,grouplist);
    if (res >=0) {
	for(i=0;i<res;i++) {
          if (grouplist[i] == gid) break;
	}
    }
  }
  if (res == -1) {
    perror("Can't get number of groups!");
    return -1;
  } else {
    return (i<res);
  }
}
