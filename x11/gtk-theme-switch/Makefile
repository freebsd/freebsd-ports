# New ports collection makefile for:	gtk-theme-switch
# Date Created:				24 July 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtk-theme-switch
PORTVERSION= 	0.4
CATEGORIES=	x11
MASTER_SITES=	http://www.muhri.net/

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Gtk.pm:${PORTSDIR}/x11-toolkits/p5-Gtk

USE_X_PREFIX=	yes

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${PREFIX}/share/gtk-theme-switch
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/gtk-theme-switch
.endif

.include <bsd.port.mk>
