# $FreeBSD$

PORTNAME=	open-motif
PORTVERSION=	2.3.4
PORTREVISION=	1
CATEGORIES=	x11-toolkits
# MASTER_SITES=	SF/${PORTNAME}/Motif%202.3.4%20Source%20Code/
MASTER_SITES=	SF/motif/Motif%202.3.4%20Source%20Code/
DISTNAME=	motif-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Motif X11 Toolkit (industry standard GUI (IEEE 1295))

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libjpeg.so:${PORTSDIR}/graphics/jpeg

MAKE_JOBS_UNSAFE=	yes
CONFLICTS=	lesstif-[0-9]*
# WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
WRKSRC=		${WRKDIR}/motif-${PORTVERSION}

USES=		gmake iconv libtool:keepla pkgconfig
USE_AUTOTOOLS=	libtoolize aclocal autoconf autoheader automake
ACLOCAL_ARGS=	-I.
AUTOMAKE_ARGS=	-a -c -f --foreign
USE_XORG=	x11 xaw xbitmaps xext xft xt
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_ENV=	LANG=C
CPPFLAGS+=	-DCSRG_BASED -DXUSE_MTSAFE_API -DXNO_MTSAFE_PWDAPI -I${PREFIX}/include
USE_CSTD=	gnu89

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
# fix sections
	@${FIND} ${WRKSRC}/doc/man/man1 -name '*.1' -maxdepth 1 | \
		${XARGS} ${REINPLACE_CMD} -e 's|user cmd|1|'
	@${FIND} ${WRKSRC}/doc/man/man3 -name '*.3' -maxdepth 1 | \
		${XARGS} ${REINPLACE_CMD} -e 's|library call|3|'
# mwmrc is not a kernel interface!!
	@cd ${WRKSRC}/doc/man && ${CP} -f man4/mwmrc.4 man5/mwmrc.5
	@${FIND} ${WRKSRC}/doc/man/man5 -name '*.5' -maxdepth 1 | \
		${XARGS} ${REINPLACE_CMD} -e 's|special file|5| ; \
		 s|file formats|5|'
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} '/^mwm_LDADD =/s/$$/ -lXt -lXext -lX11/' \
		${WRKSRC}/clients/mwm/Makefile.am
	@${REINPLACE_CMD} '/^uil_LDADD =/s/$$/ -lXt/' \
		${WRKSRC}/clients/uil/Makefile.am
	@${REINPLACE_CMD} '/^LDADD =/s/\\*$$/ -lXt -lX11 &/' \
		${WRKSRC}/clients/xmbind/Makefile.am \
		${WRKSRC}/demos/doc/programGuide/ch05/Scale/Makefile.am \
		${WRKSRC}/demos/doc/programGuide/ch06/combo_box/Makefile.am \
		${WRKSRC}/demos/doc/programGuide/ch06/spin_box/Makefile.am \
		${WRKSRC}/demos/doc/programGuide/ch08/Container/Makefile.am \
		${WRKSRC}/demos/doc/programGuide/ch08/Notebook/Makefile.am \
		${WRKSRC}/demos/doc/programGuide/ch16/Makefile.am \
		${WRKSRC}/demos/doc/programGuide/ch17/simple_drag/Makefile.am \
		${WRKSRC}/demos/doc/programGuide/ch17/simple_drop/Makefile.am \
		${WRKSRC}/demos/programs/ColorSel/Makefile.am \
		${WRKSRC}/demos/programs/Column/Makefile.am \
		${WRKSRC}/demos/programs/Exm/simple_app/Makefile.am \
		${WRKSRC}/demos/programs/Ext18List/Makefile.am \
		${WRKSRC}/demos/programs/IconB/Makefile.am \
		${WRKSRC}/demos/programs/TabStack/Makefile.am \
		${WRKSRC}/demos/programs/Tree/Makefile.am \
		${WRKSRC}/demos/programs/airport/Makefile.am \
		${WRKSRC}/demos/programs/animate/Makefile.am \
		${WRKSRC}/demos/programs/drag_and_drop/Makefile.am \
		${WRKSRC}/demos/programs/draw/Makefile.am \
		${WRKSRC}/demos/programs/filemanager/Makefile.am \
		${WRKSRC}/demos/programs/fileview/Makefile.am \
		${WRKSRC}/demos/programs/getsubres/Makefile.am \
		${WRKSRC}/demos/programs/i18ninput/Makefile.am \
		${WRKSRC}/demos/programs/panner/Makefile.am \
		${WRKSRC}/demos/programs/periodic/Makefile.am \
		${WRKSRC}/demos/programs/piano/Makefile.am \
		${WRKSRC}/demos/programs/popups/Makefile.am \
		${WRKSRC}/demos/programs/sampler2_0/Makefile.am \
		${WRKSRC}/demos/programs/setdate/Makefile.am \
		${WRKSRC}/demos/programs/workspace/Makefile.am \
		${WRKSRC}/demos/unsupported/aicon/Makefile.am \
		${WRKSRC}/demos/unsupported/dainput/Makefile.am \
		${WRKSRC}/demos/unsupported/dogs/Makefile.am \
		${WRKSRC}/demos/unsupported/motifshell/Makefile.am \
		${WRKSRC}/demos/unsupported/xmapdef/Makefile.am \
		${WRKSRC}/demos/unsupported/xmfonts/Makefile.am
	@${REINPLACE_CMD} '/^LDADD =/s/$$/ -lXt/' \
		${WRKSRC}/demos/lib/Exm/wml/Makefile.am \
		${WRKSRC}/demos/lib/Xmd/Makefile.am \
		${WRKSRC}/demos/programs/ButtonBox/Makefile.am \
		${WRKSRC}/demos/programs/Combo2/Makefile.am \
		${WRKSRC}/demos/programs/FontSel/Makefile.am \
		${WRKSRC}/demos/programs/Outline/Makefile.am \
		${WRKSRC}/demos/programs/Paned/Makefile.am \
		${WRKSRC}/demos/programs/hellomotif/Makefile.am \
		${WRKSRC}/demos/programs/hellomotifi18n/Makefile.am \
		${WRKSRC}/demos/programs/tooltips/Makefile.am \
		${WRKSRC}/demos/unsupported/hellomotif/Makefile.am \
		${WRKSRC}/demos/unsupported/xmforc/Makefile.am \
		${WRKSRC}/demos/unsupported/xmform/Makefile.am
	@${REINPLACE_CMD} '/^LDADD =/s/\\*$$/ -lXt -lXext -lX11 &/' \
		${WRKSRC}/demos/programs/Exm/app_in_c/Makefile.am \
		${WRKSRC}/demos/programs/earth/Makefile.am \
		${WRKSRC}/demos/programs/todo/Makefile.am
	@${REINPLACE_CMD} '/^wmldbcreate_LDADD =/s/$$/ -lXt/' \
		${WRKSRC}/tools/wml/Makefile.am

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in BUGREPORT README RELNOTES
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
