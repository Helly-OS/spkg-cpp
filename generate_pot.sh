#s!/bin/bash

PROGS=("spkg")
LANGUAGES=("es")
CURDIR=$(pwd)
LOCALEDIR="../locale"


for i in $PROGS;
do
      if [ -d $i ]
      then
            cd $i

            [ ! -d pot ] && mkdir -p pot
            xgettext --keyword=_ --language=C --add-comments --sort-output -o pot/$i.pot *.cpp

            for j in ${LANGUAGES[@]}
            do
                  [ ! -d po/$j ] && mkdir -p po/$j
                  if [ -f po/$j/$i.po ]
                  then
                        msgmerge --output-file=po/$j/$i.po po/$j/$i.po pot/$i.pot
                  else
                        if [ -f pot/$i.pot ]
                        then
                              cp -avf pot/$i.pot po/$j/$i.po
                        fi
                  fi

                  [ ! -d $LOCALEDIR/$j/LC_MESSAGES ] && mkdir -p $LOCALEDIR/$j/LC_MESSAGES
                  if [ -f po/$j/$i.po ]
                  then
                        [ -f $LOCALEDIR/$j/LC_MESSAGES/$i.mo ] && rm -fv $LOCALEDIR/$j/LC_MESSAGES/$i.mo
                        msgfmt --output-file=$LOCALEDIR/$j/LC_MESSAGES/$i.mo po/$j/$i.po
                  fi
            done

            cd $CURDIR
      fi
done
