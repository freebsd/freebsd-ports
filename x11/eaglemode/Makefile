# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	eaglemode
PORTVERSION=	0.89.0
CATEGORIES=	x11
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Futuristic zoomable user environment

LICENSE=	GPLv3

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libfreetype.so:${PORTSDIR}/print/freetype2

USES=		compiler:features jpeg perl5 pkgconfig shebangfix tar:bzip2
USE_PERL5=	build
USE_XORG=	x11 xext xxf86vm
SUB_FILES=	eaglemode.sh
WANT_GNOME=	yes

BUILD_ARGS=	continue=no

.for lib in X11 jpeg png tiff
BUILD_ARGS+=	${lib}-inc-dir="${LOCALBASE}/include" \
		${lib}-lib-dir="${LOCALBASE}/lib"
.endfor

DATADIR=	${PREFIX}/lib/${PORTNAME}
PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

OPTIONS_DEFINE=	XINE RSVG PDF
OPTIONS_DEFAULT=XINE RSVG PDF
RSVG_DESC=	SVG support through librsvg
PDF_DESC=	PDF support through poppler-glib

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == gcc && ${COMPILER_VERSION} <= 42
USE_GCC=	yes
.endif

.if ${PORT_OPTIONS:MXINE}
LIB_DEPENDS+=	libxine.so:${PORTSDIR}/multimedia/libxine
BUILD_ARGS+=	xine-inc-dir="${LOCALBASE}/include" \
		xine-lib-dir="${LOCALBASE}/lib"
PLIST_SUB+=	EMAV=""
.else
PLIST_SUB+=	EMAV="@comment "
.endif

.if ${PORT_OPTIONS:MRSVG}
USE_GNOME+=	librsvg2
PLIST_SUB+=	EMSVG=""
.else
PLIST_SUB+=	EMSVG="@comment "
.endif

.if ${PORT_OPTIONS:MPDF}
LIB_DEPENDS+=	libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib
USE_GNOME+=	gtk20
PLIST_SUB+=	EMPDF=""
.else
PLIST_SUB+=	EMPDF="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|; s|"-O2"|"${CFLAGS}"|' \
		${WRKSRC}/makers/unicc/plugins/unicc_gnu.pm
.if ! ${PORT_OPTIONS:MXINE}
	@${RM} -f ${WRKSRC}/makers/emAv.maker.pm
.endif
.if ! ${PORT_OPTIONS:MRSVG}
	@${RM} -f ${WRKSRC}/makers/emSvg.maker.pm
.endif
.if ! ${PORT_OPTIONS:MPDF}
	@${RM} -f ${WRKSRC}/makers/emPdf.maker.pm
.endif
	@${FIND} ${WRKSRC} -name "*.pl" | ${XARGS} \
		${REINPLACE_CMD} -e '1s|${perl_OLD_CMD}|${perl_CMD}|'

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PERL} make.pl build ${BUILD_ARGS})

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${PERL} make.pl install dir=${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/eaglemode.sh ${STAGEDIR}${PREFIX}/bin/eaglemode
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/eaglemode/bin/* \
		${STAGEDIR}${PREFIX}/lib/eaglemode/lib/*.so \
		${STAGEDIR}${PREFIX}/lib/eaglemode/lib/emClock/emTimeZonesProc \
		${STAGEDIR}${PREFIX}/lib/eaglemode/lib/emTmpConv/emTmpConvProc
.if ${PORT_OPTIONS:MXINE}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/eaglemode/lib/emAv/emAvServerProc_xine
.endif
.if ${PORT_OPTIONS:MRSVG}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/eaglemode/lib/emSvg/emSvgServerProc
.endif
.if ${PORT_OPTIONS:MPDF}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/eaglemode/lib/emPdf/emPdfServerProc
.endif

.include <bsd.port.post.mk>
