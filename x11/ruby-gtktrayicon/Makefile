# New ports collection makefile for:	ruby-gtktrayicon
# Date created:		29 June 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	gtktrayicon
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	x11 gnome ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ruby-gnome2
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-gtktrayicon-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ruby binding for GtkTrayIcon

BUILD_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2

BROKEN=		"Configure fails"
EXPIRATION_DATE=2005-02-18
DEPRECATED=	${BROKEN}

USE_RUBY=	yes
USE_GNOME=	gtk20
USE_RUBY_EXTCONF=	yes
USE_XLIB=	yes

INSTALL_TARGET=	site-install

.include <bsd.port.mk>
