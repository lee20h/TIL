<template>
  <div>
      <h1>
          Today I Leanred
          <br>
          <div class = "rightcontainer">
            TIL
          </div>
      </h1>
      <h2 class = "rightcontainer">
        20h's TIL
      </h2>
  </div>
</template>

<script>
</script>

<style>
@import "https://fonts.googleapis.com/css?family=Oswald";
.rightcontainer {
  text-align: right;
}
h1 {
  font-family: "Oswald";
  font-weight: 500;
  border-bottom: 17px solid #5AA1E7;
  word-break: keep-all;
  font-size: 5rem;
}

@media (max-width: 550px) {
  h1 {
    font-size: 3.4rem;
  }
}
@media (max-width: 430px) {
  h1 {
    font-size: 3.4rem;
  }
}
</style>