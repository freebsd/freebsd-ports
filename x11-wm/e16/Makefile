# New ports collection makefile for:	enlightenment
# Date created:			10 June 1997
# Whom:				Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	enlightenment
PORTVERSION=	0.16.7.1
PORTREVISION=	0
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	A very artistic X window manager

LIB_DEPENDS=	Imlib2.2:${PORTSDIR}/graphics/imlib2

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	esound
USE_ICONV=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-fsstd --disable-hints-gnome --disable-hints-kde
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

MAN1=		enlightenment.1

.include <bsd.port.pre.mk>

.if (${MACHINE} == "alpha") && (${XFREE86_VERSION} == 3)
CONFIGURE_ARGS+=	--disable-zoom
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| wctype.h||g ; \
		 s|-ldl||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/scripts/e_gen_menu

.include <bsd.port.post.mk>
