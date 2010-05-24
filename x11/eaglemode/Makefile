# New ports collection makefile for:	eaglemode
# Date created:		29 Apr 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	eaglemode
PORTVERSION=	0.77.0
CATEGORIES=	x11
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Futuristic zoomable user environment

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		freetype.9:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
USE_PERL5_BUILD=	yes
USE_XORG=	x11 xext xxf86vm
SUB_FILES=	eaglemode.sh

BUILD_ARGS=	continue=no

.for lib in X11 jpeg png tiff
BUILD_ARGS+=	${lib}-inc-dir="${LOCALBASE}/include" \
		${lib}-lib-dir="${LOCALBASE}/lib"
.endfor

OPTIONS=	XINE "Video playback support through libxine" on

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64" && ${OSVERSION} < 700000
BROKEN=		Does not build on sparc64-6
.endif

.if !defined(WITHOUT_XINE)
LIB_DEPENDS+=	xine.1:${PORTSDIR}/multimedia/libxine
BUILD_ARGS+=	xine-inc-dir="${LOCALBASE}/include" \
		xine-lib-dir="${LOCALBASE}/lib"
PLIST_SUB=	EMAV=""
.else
PLIST_SUB=	EMAV="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|; s|"-O2"|"${CFLAGS}"|' \
		${WRKSRC}/makers/unicc/plugins/unicc_gnu.pm
.if defined(WITHOUT_XINE)
	@${RM} -f ${WRKSRC}/makers/emAv.maker.pm
.endif

do-build:
	cd ${WRKSRC} && ${PERL} make.pl build ${BUILD_ARGS}

do-install:
	${MKDIR} ${PREFIX}/lib/eaglemode
	cd ${WRKSRC} && ${PERL} make.pl install dir=${PREFIX}/lib/eaglemode
	${INSTALL_SCRIPT} ${WRKDIR}/eaglemode.sh ${PREFIX}/bin/eaglemode

.include <bsd.port.post.mk>
