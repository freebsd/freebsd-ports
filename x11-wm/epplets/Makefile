# New ports collection makefile for:   epplets
# Date created:        18 October 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	epplets
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	enlightenment

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A collection of Enlightenment dock applications

BUILD_DEPENDS=	enlightenment:${PORTSDIR}/x11-wm/enlightenment
LIB_DEPENDS=	cdaudio.1:${PORTSDIR}/audio/libcdaudio \
		gtop.1:${PORTSDIR}/devel/libgtop \
		epplet.1:${PORTSDIR}/x11-wm/libepplet
RUN_DEPENDS=	import:${PORTSDIR}/graphics/ImageMagick \
		enlightenment:${PORTSDIR}/x11-wm/enlightenment

USE_X_PREFIX=	yes
USE_GNOME=	esound
USE_GL=		yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	EROOT="${X11BASE}/share/enlightenment" \
		EBIN="${X11BASE}/bin" \
		CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--enable-fsstd

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
APM_PROGS=	E-Power.epplet
PLIST_SUB+=	APM_PROGS=""
.else
APM_PROGS=	# none
PLIST_SUB+=	APM_PROGS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|@APM_PROGS@|${APM_PROGS}|g' ${WRKSRC}/epplets/Makefile.in

.include <bsd.port.post.mk>
