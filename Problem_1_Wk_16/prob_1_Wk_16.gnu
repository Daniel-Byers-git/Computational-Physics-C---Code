set xlabel 'time'
set ylabel 'x'
set zlabel 'Temp'

set xrange [0.:1000.]
set yrange [0.:1.]
set zrange [.001:100.]

splot 'tempdata.dat' u 1:2:3 with lines
