# Created by: dmitry@karasik.eu.org
# $FreeBSD$

PORTNAME=	Prima
PORTVERSION=	1.37
CATEGORIES=	x11-toolkits graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extensible Perl toolkit for multi-platform GUI development

LICENSE=	BSD

LIB_DEPENDS=	libgif.so:${PORTSDIR}/graphics/giflib \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff

OPTIONS_DEFINE=	GTK2 ICONV XFT
OPTIONS_DEFAULT=ICONV XFT

CONFIGURE_ARGS=	X11BASE=${LOCALBASE}
USES=		perl5
USE_PERL5=	configure
USE_XORG=	x11 xext xpm xrender
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXFT}
USE_XORG+=	xft
.if ${PORT_OPTIONS:MICONV}
USES+=		iconv
.else
CONFIGURE_ARGS+=WITH_ICONV=0
.endif
.else
CONFIGURE_ARGS+=WITH_XFT=0
.endif

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME=	gtk20
CONFIGURE_ARGS+=WITH_GTK2=1
.endif

.include <bsd.port.mk>
