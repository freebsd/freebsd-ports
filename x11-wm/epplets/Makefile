# New ports collection makefile for:   epplets
# Date created:        18 October 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	epplets
PORTVERSION=	0.7
PORTREVISION=	5
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	enlightenment

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A collection of Enlightenment dock applications

BUILD_DEPENDS=	e16:${PORTSDIR}/x11-wm/enlightenment
LIB_DEPENDS=	cdaudio.1:${PORTSDIR}/audio/libcdaudio \
		epplet.1:${PORTSDIR}/x11-wm/libepplet
RUN_DEPENDS=	import:${PORTSDIR}/graphics/ImageMagick \
		e16:${PORTSDIR}/x11-wm/enlightenment

USE_X_PREFIX=	yes
USE_GNOME=	esound lthack
USE_GL=		yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	EROOT="${X11BASE}/share/enlightenment" \
		EBIN="${X11BASE}/bin" \
		CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--enable-fsstd
MAKE_ARGS=	SUBDIRS="epplets debian"

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
APM_PROGS=	E-Power.epplet
PLIST_SUB+=	APM_PROGS=""
.else
APM_PROGS=	# none
PLIST_SUB+=	APM_PROGS="@comment "
.endif

post-extract:
	@${RM} -f ${WRKSRC}/api/epplet.h*

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's| ../api/epplet.h||g ; \
		 s|@APM_PROGS@|${APM_PROGS}|g'
	@${REINPLACE_CMD} -e 's| api/epplet.h||g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
