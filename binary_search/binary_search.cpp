bool isOK(int index, int key){
  /*indexが条件を満たすかどうかを判定(今回はkeyよりおおきいか)*/
  if(a[index]>=key) return true;
  else return false;
}

int binary_search(int key){
  int ng = -1;
  int ok = (int)a.size();
  //okとngの初期値によって最大値だけでなく最小値も求められる.
  //ng=-1の時はkey以上の数値の最小値

  while(abs(ok - ng) > 1){
    int mid = (ok + ng) / 2;

    if(isOK(mid,key)) ok = mid;
    else ng = mid;
  }

  return ok;
}
