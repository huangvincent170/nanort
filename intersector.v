module intersector
(
    input signed [31:0] min_t,
    input signed [31:0] max_t,
    input signed [31:0] bmin0,
    input signed [31:0] bmin1,
    input signed [31:0] bmin2,
    input signed [31:0] bmax0,
    input signed [31:0] bmax1,
    input signed [31:0] bmax2,
    input signed [31:0] ray_org0,
    input signed [31:0] ray_org1,
    input signed [31:0] ray_org2,
    input signed [31:0] ray_inv_dir0,
    input signed [31:0] ray_inv_dir1,
    input signed [31:0] ray_inv_dir2,
    input signed [31:0] ray_dir_sign0,
    input signed [31:0] ray_dir_sign1,
    input signed [31:0] ray_dir_sign2,
    output wire signed [31:0] tmin,
    output wire signed [31:0] tmax
);

wire signed [31:0] min_x;
wire signed [31:0] min_y;
wire signed [31:0] min_z;
wire signed [31:0] max_x;
wire signed [31:0] max_y;
wire signed [31:0] max_z;

wire signed [31:0] tmin_x;
wire signed [31:0] tmin_y;
wire signed [31:0] tmin_z;
wire signed [31:0] tmax_x;
wire signed [31:0] tmax_y;
wire signed [31:0] tmax_z;

assign min_x = ray_dir_sign0 > 0 ? bmax0 : bmin0;
assign min_y = ray_dir_sign1 > 0 ? bmax1 : bmin1;
assign min_z = ray_dir_sign2 > 0 ? bmax2 : bmin2;
assign max_x = ray_dir_sign0 > 0 ? bmin0 : bmax0;
assign max_y = ray_dir_sign1 > 0 ? bmin1 : bmax1;
assign max_z = ray_dir_sign2 > 0 ? bmin2 : bmax2;

// X
assign tmin_x = (min_x - ray_org0) * ray_inv_dir0;
// MaxMult robust BVH traversal(up to 4 ulp).
// 1.0000000000000004 for double precision.
//assign tmax_x = (max_x - ray_org0) * ray_inv_dir0 * 1.00000024;
assign tmax_x = (max_x - ray_org0) * ray_inv_dir0;


// Y
assign tmin_y = (min_y - ray_org1) * ray_inv_dir1;
//assign tmax_y = (max_y - ray_org1) * ray_inv_dir1 * 1.00000024;
assign tmax_y = (max_y - ray_org1) * ray_inv_dir1;

// Z
assign tmin_z = (min_z - ray_org2) * ray_inv_dir2;
//assign tmax_z = (max_z - ray_org2) * ray_inv_dir2 * 1.00000024;
assign tmax_z = (max_z - ray_org2) * ray_inv_dir2;

// assign tmin = safemax(tmin_z, safemax(tmin_y, safemax(tmin_x, min_t)));

assign tmin = tmin_z > (tmin_y > ((tmin_x > min_t) ? tmin_x : min_t) ? tmin_y : ((tmin_x > min_t) ? tmin_x : min_t))
    ? tmin_z : (tmin_y > ((tmin_x > min_t) ? tmin_x : min_t) ? tmin_y : ((tmin_x > min_t) ? tmin_x : min_t));

// assign tmax = safemin(tmax_z, safemin(tmax_y, safemin(tmax_x, max_t)));
assign tmax =  tmax_z < (tmax_y < ((tmax_x < min_t) ? tmax_x : max_t) ? tmax_y : ((tmax_x < max_t) ? tmax_x : max_t))
    ? tmax_z : (tmax_y < ((tmax_x < max_t) ? tmax_x : max_t) ? tmax_y : ((tmax_x < max_t) ? tmax_x : max_t));

initial begin
$display("%d min_t  ", min_t);
$display("%d max_t  ", max_t);
$display("%d bmin0  ", bmin0);
$display("%d bmin1  ", bmin1);
$display("%d bmin2  ", bmin2);
$display("%d bmax0  ", bmax0);
$display("%d bmax1  ", bmax1);
$display("%d bmax2  ", bmax2);
$display("%d ray_org0  ", ray_org0);
$display("%d ray_org1 ", ray_org1);
$display("%d ray_org2  ", ray_org2);
$display("%d ray_inv_dir0  ", ray_inv_dir0);
$display("%d ray_inv_dir1  ", ray_inv_dir1);
$display("%d ray_inv_dir2  ", ray_inv_dir2);
$display("%d ray_dir_sign0 ", ray_dir_sign0);
$display("%d ray_dir_sign1  ", ray_dir_sign1);
$display("%d ray_dir_sign2  ", ray_dir_sign2);

$display("%d min_x ", min_x);
$display("%d min_y ", min_y);
$display("%d min_z ", min_z);
$display("%d max_x ", max_x);
$display("%d max_y ", max_y);
$display("%d max_z ", max_z);


$display("%d tmin_x ", tmin_x);
$display("%d tmax_x ", tmax_x);

$display("%d tmin_y ", tmin_y);
$display("%d tmax_y ", tmax_y);

$display("%d tmin_z ", tmin_z);
$display("%d tmax_z ", tmax_z);

$display("%d tmax ", tmax);
$display("%d tmin ", tmin);
    $finish;
end
endmodule

