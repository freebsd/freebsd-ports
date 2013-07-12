# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	eaglemode
PORTVERSION=	0.84.0
CATEGORIES=	x11
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Futuristic zoomable user environment

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff \
		freetype:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
USE_PERL5_BUILD=yes
USE_XORG=	x11 xext xxf86vm
SUB_FILES=	eaglemode.sh

BUILD_ARGS=	continue=no

.for lib in X11 jpeg png tiff
BUILD_ARGS+=	${lib}-inc-dir="${LOCALBASE}/include" \
		${lib}-lib-dir="${LOCALBASE}/lib"
.endfor

OPTIONS_DEFINE=	XINE RSVG PDF
OPTIONS_DEFAULT=RSVG PDF
RSVG_DESC=	SVG support through librsvg
PDF_DESC=	PDF support through poppler-glib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXINE}
LIB_DEPENDS+=	xine:${PORTSDIR}/multimedia/libxine
BUILD_ARGS+=	xine-inc-dir="${LOCALBASE}/include" \
		xine-lib-dir="${LOCALBASE}/lib"
PLIST_SUB+=	EMAV=""
BROKEN=		does not build with libxine 1.2.x
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
LIB_DEPENDS+=	poppler-glib:${PORTSDIR}/graphics/poppler-glib
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

do-build:
	cd ${WRKSRC} && ${PERL} make.pl build ${BUILD_ARGS}

do-install:
	${MKDIR} ${PREFIX}/lib/eaglemode
	cd ${WRKSRC} && ${PERL} make.pl install dir=${PREFIX}/lib/eaglemode
	${INSTALL_SCRIPT} ${WRKDIR}/eaglemode.sh ${PREFIX}/bin/eaglemode

.include <bsd.port.mk>
