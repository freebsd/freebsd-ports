# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xfce4-conf
PORTVERSION=	4.12.1
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/src/xfce/xfconf/${PORTVERSION:R}
DISTNAME=	xfconf-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	D-Bus-based configuration storage system

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-XML-Parser>=2.44:textproc/p5-XML-Parser
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib

USES=		gettext-tools gmake gnome libtool pathfix perl5 pkgconfig \
		tar:bzip2 xfce
USE_GNOME=	glib20 gtk20 intlhack intltool
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_XFCE=	libutil
USE_XORG=	x11

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--without-html-dir

OPTIONS_DEFINE=		PERL NLS
OPTIONS_SUB=		yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

PERL_BUILD_DEPENDS=	p5-ExtUtils-Depends>=0.405:devel/p5-ExtUtils-Depends \
			p5-ExtUtils-PkgConfig>=1.15:devel/p5-ExtUtils-PkgConfig \
			p5-Glib2>=1.321:devel/p5-Glib2
PERL_CONFIGURE_ENABLE=	perl-bindings
PERL_USE=		perl5=run

.include <bsd.port.mk>
