# Important Flags

`"-bs-super-errors"`

# Namespace

`"namespace": true`


# Auto interface generation

To generate .rei files you need to run first the following

`bsc lib/bs/src/MyUtils-MyProject.cmi`

and then the following command

`bsc -bs-re-out lib/bs/src/MyUtils-MyProject.cmi > MyUtils.rei`

MyUtils is a module name
MyProject is namespace name
