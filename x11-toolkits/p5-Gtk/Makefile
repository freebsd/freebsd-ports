# New ports collection makefile for:	p5-Gtk
# Date created:		28 Oct 1997
# Whom:	      		Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $FreeBSD$
#

PORTNAME=	Gtk
PORTVERSION= 	0.7003
CATEGORIES=	x11-toolkits lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Gtk
DISTNAME=	${PORTNAME}-Perl-${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	vanilla@FreeBSD.org

USE_PERL5=	yes
USE_IMLIB=	yes

MAN3=		Gtk::GtkColorSelectButton.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL \
	--with-gdkimlib --without-gnome CC="${CC}" CCFLAGS="${CFLAGS}"

.include <bsd.port.mk>
